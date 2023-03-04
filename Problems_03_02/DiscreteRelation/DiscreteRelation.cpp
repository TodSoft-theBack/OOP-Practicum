#include <iostream>
#include <fstream>

namespace Relations
{
    struct Pair {
        unsigned first;
        unsigned second;
    };
    void PrintPair(const Pair& pair) {
        std::cout << "< " << pair.first << ", " << pair.second << " >" << std::endl;
    }

    struct Relation
    {
        static const size_t MAX_RELATION_SIZE = 25;
        Pair pairs[MAX_RELATION_SIZE];
        size_t current_size = 0;
    };

    void PrintRelation(const Relation& relation) 
    {
        for (size_t i = 0; i < relation.current_size; i++)
            PrintPair(relation.pairs[i]);
    }

    bool AddToRelation(Relation& relation, const Pair& pair)
    {
        if (relation.current_size >= Relation::MAX_RELATION_SIZE)
            return false;
        relation.pairs[relation.current_size++] = pair;
        return true;
    }

    void SavePairToFile(std::ofstream& writer, const Pair& pair)
    {
        writer << pair.first << " " << pair.second << std::endl;
    }

    bool SaveToFile(const char* fileName, const Relation& relation)
    {
        std::ofstream writer(fileName);
        if (!writer.is_open())
            return false;
        writer << relation.current_size << std::endl;
        for (size_t i = 0; i < relation.current_size; i++)
            SavePairToFile(writer, relation.pairs[i]);

        writer.close();
        return true;
    }
    void ReadPair(std::ifstream& reader, Pair& pair)
    {
        reader >> pair.first >> pair.second;
    }
    Relation* ReadFromFile(const char* fileName)
    {
        std::ifstream reader(fileName);
        if (!reader.is_open())
            return nullptr;
        Relation* relation = new Relation;
        size_t relation_size;
        reader >> relation_size;
        relation->current_size = relation_size;
        for (size_t i = 0; i < relation_size; i++)
            ReadPair(reader, relation->pairs[i]);

        reader.close();
        return relation;
    }
}

const char fileName[] = "relation.txt";

int main()
{
    using namespace Relations;
    Relation relation;
    AddToRelation(relation, { 1,1 });
    AddToRelation(relation, { 1,2 });
    AddToRelation(relation, { 2,1 });
    AddToRelation(relation, { 1,3 });
    AddToRelation(relation, { 3,1 });

    SaveToFile(fileName, relation);
    Relation* savedRelation = ReadFromFile(fileName);
    if (savedRelation != nullptr)
        PrintRelation(*savedRelation);
    delete savedRelation;
}