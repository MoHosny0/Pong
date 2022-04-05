#ifndef SCORE_H
#define SCORE_H

/**
    @brief Un score int. 
*/

class Score 
{
    private:
        int score;

    public:
        /**
        @brief Construct du score. 
        */
        Score();

        /**
        @brief Accesseur de score int
        */
        const int getScore() const;

        /**
        @brief Mutateur du score. 
        */
        void setScore();
        
};



#endif