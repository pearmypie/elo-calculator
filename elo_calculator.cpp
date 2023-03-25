/* CATANA IOAN-ALEXANDRU */
/* 22/12/2022            */   
/* ELO CALCULATOR        */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_header()
{
    printf("C/C++ Elo Calculator\n\n");
}

void input_player_ratings(float* rating_A, float* rating_B)
{
    printf("Input Player A's rating: ");
    scanf_s("%f", rating_A);

    printf("Input Player B's rating: ");
    scanf_s("%f", rating_B);
}

void compute_expected_scores(float* expected_score_A, float* expected_score_B, float* player_rating_A, float* player_rating_B)
{
    *expected_score_A = 1 / (1 + pow(10, (*player_rating_B - *player_rating_A) / 400));
    *expected_score_B = 1 / (1 + pow(10, (*player_rating_A - *player_rating_B) / 400));
}

void input_match_score(float* score, float* actual_score_A, float* actual_score_B)
{
    /* I have made sure this function will not break the program if given incorrect inputs */
    bool input_correct;

    do
    {
        input_correct = true;

        printf("Input the result of the match: ");
        scanf_s("%f", score);

        if (*score == 1.0)
        {
            *actual_score_A = 1;
            *actual_score_B = 0;
        }
        else if (*score == 0.0)
        {
            *actual_score_A = 0;
            *actual_score_B = 1;
        }
        else if (*score == 0.5)
        {
            *actual_score_A = 0.5;
            *actual_score_B = 0.5;
        }
        else
        {
            printf("\nThe score can be either 1, 0.5, or 0\n");
            input_correct = false;
        }
    } while (!input_correct);
}

void compute_new_ratings(float* new_rating_A, float* new_rating_B, float player_rating_A, float player_rating_B, float actual_score_A, float expected_score_A, float actual_score_B, float expected_score_B, int K)
{
    *new_rating_A = player_rating_A + K * (actual_score_A - expected_score_A);
    *new_rating_B = player_rating_B + K * (actual_score_B - expected_score_B);
}

void display_new_ratings(float new_rating_A, float player_rating_A, float new_rating_B, float player_rating_B)
{
    if (new_rating_A > player_rating_A)
    {
        printf("\n");
        printf("Player A's new rating is %.2f (+%.2f)\n", new_rating_A, fabs(new_rating_A - player_rating_A));
        printf("Player B's new rating is %.2f (-%.2f)\n", new_rating_B, fabs(new_rating_B - player_rating_B));
    }
    else
    {
        printf("\n");
        printf("Player A's new rating is %.2f (-%.2f)\n", new_rating_A, fabs(new_rating_A - player_rating_A));
        printf("Player B's new rating is %.2f (+%.2f)\n", new_rating_B, fabs(new_rating_B - player_rating_B));
    }
}

int main()
{
    float player_rating_A ;
    float player_rating_B ;
    float expected_score_A;
    float expected_score_B;
    float new_rating_A    ;
    float new_rating_B    ;
    float actual_score_A  ;
    float actual_score_B  ;
    float score           ;

    print_header();
    input_player_ratings(&player_rating_A, &player_rating_B);
    compute_expected_scores(&expected_score_A, &expected_score_B, &player_rating_A, &player_rating_B);
    input_match_score(&score, &actual_score_A, &actual_score_B);
    compute_new_ratings(&new_rating_A, &new_rating_B, player_rating_A, player_rating_B, actual_score_A, expected_score_A, actual_score_B, expected_score_B, 32);
    display_new_ratings(new_rating_A, player_rating_A, new_rating_B, player_rating_B);

    system("pause");
}


