#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)

namespace ProblemBase 
{ 
    const size_t MAX_EXPLANATION_SIZE = 512;
    const size_t MAX_PASSWORD_SIZE = 256;
    const char DEFAULT_PASSWORD[20] = "< Empty password >";
    const char DEFAULT_EXPLANATION[22] = "< Empty explanation >";
    const char DEFAULT_CORRECTANSWER = 'p';

    class Problem 
    {
        private:
            char _explanation[MAX_EXPLANATION_SIZE];
            char _correctAnswer;
            unsigned _points;
            char _password[MAX_PASSWORD_SIZE];

            void SetPassword(const char* password)
            {
                strcpy(_password, DEFAULT_PASSWORD);

                size_t len = strlen(password);
                if (len > 0 && len < MAX_PASSWORD_SIZE)
                    strcpy(_password, password);                   
            }  
            void SetExplanation()
            {
                strcpy(_explanation, DEFAULT_EXPLANATION);
            }
            void SetPoints()
            {
                _points = 0;
            }
            void SetCorrectAnswer()
            {
                _correctAnswer = DEFAULT_CORRECTANSWER;
            }

            bool IsValidAnswer(const char symbol) {
                return symbol >= 'a' && symbol <= 'd';
            }
    
        public:
            Problem(const char* password) {
                SetPassword(password);
                SetExplanation();
                SetCorrectAnswer();
                SetPoints();
            }
            
            void SetExplanation(const char* password, const char* NewExplanation)
            {
                size_t len = strlen(NewExplanation);
                if (AuthenticatePassword(password) && len > 0 && len < MAX_EXPLANATION_SIZE )
                    strcpy(_explanation, NewExplanation);
            }
            void SetPoints(const char* password, unsigned points)
            {
                if (AuthenticatePassword(password))
                    _points = points;
            }
            void SetCorrectAnswer(const char* password, const char correctAnswer)
            {
                if (AuthenticatePassword(password) && IsValidAnswer(correctAnswer))
                    _correctAnswer = correctAnswer;
            }

            const char* Explanation()
            {
                return _explanation;
            }

            unsigned Points()
            {
                return _points;
            }

            bool AuthenticatePassword(const char* password)
            {
                return strcmp(password, _password) == 0;
            }

            bool VerifyAnswer(char answer)
            {
                return answer == _correctAnswer;
            }
    };

    Problem* ReadFromFile(const char* filename, size_t& test_count)
    {
        std::ifstream file(filename, std::ios::in | std::ios::binary);
        if (!file.is_open())
            return;
    }

    void FreeProblems(Problem* problems) {
        delete[] problems;
    }

    void WriteToFile(const char* filename,  Problem* test, size_t count)
    {
        std::ofstream file(filename, std::ios::out | std::ios::binary);
        if (!file.is_open())
            return;
        file.write((const char*)test, count * sizeof(Problem));
    }
};

int main()
{
    char password[5] = "meme";
    size_t test_count = 0;
    ProblemBase::Problem* problems = ProblemBase::ReadFromFile("Problem.bin", test_count);
    ProblemBase::WriteToFile("Problem.bin", problems, test_count);

    /*pepe.SetExplanation(password, "Write this code correctly, pls! :') ");
    pepe.SetExplanation("pepe", "Shit your pants ASAP!");
    pepe.SetCorrectAnswer("pepe", 'a');
    pepe.SetCorrectAnswer(password, 'd');
    pepe.SetPoints("pepe", 69);
    pepe.SetPoints(password, 10);*/
}