#include <bits/stdc++.h>
using namespace std;
long long numberOfGames;// 1 ≤ k ≤ 10^18 , numberOfGames (k) is number of games
int aChoice[1000], bChoice[1000];//a for Alice robot's choice & b for bob robot's choice
int Alice[3][3], Bob[3][3];// 1 ≤ a, b ≤ 3
int calCycleOccurrence[3][3];
int numOfChoices,lastChoice;
long long scoreOfAlice=0,scoreOfBob=0;
//to calculate choices of both robots
void Choices()
{
    for (int i=2; ; i++)
    {
        aChoice[i] = Alice[aChoice[i-1]][bChoice[i-1]]-1;//know the next choice for Alice robot
        bChoice[i] = Bob[aChoice[i-1]][bChoice[i-1]]-1;//know the next choice for Bob robot
        //if next choice isn't repeted
        if(calCycleOccurrence[aChoice[i]][bChoice[i]]==0)
        {
            calCycleOccurrence[aChoice[i]][bChoice[i]] = i;
        }
        //if next choice is repeted i will get the value of first choice of this choice
        else
        {
            numOfChoices = i-calCycleOccurrence[aChoice[i]][bChoice[i]];
            lastChoice = i;
            break;
        }
    }
}
//calculate scores for both robots
// 0(rock) beat 1(scicssor) , 1 beat 2(paper) , 2 beat 0 if alice is first choice and bob is scond choice
void calculateScore()
{
    //calculate score before repetition
    for (int i=1; i<lastChoice-numOfChoices && i<=numberOfGames; i++)
    {
        if (aChoice[i]==1 && bChoice[i]==0  ||aChoice[i]==2 && bChoice[i]==1 ||aChoice[i]==0 && bChoice[i]==2)
        {
            scoreOfAlice++;
        }
        if (aChoice[i]==0 && bChoice[i]==1 ||aChoice[i]==1 && bChoice[i]==2 ||aChoice[i]==2 && bChoice[i]==0)
        {
            scoreOfBob++;
        }
    }
    //calculate score after repetition
    for (int i=lastChoice-numOfChoices; i<lastChoice && i<=numberOfGames; i++)
    {
        if (aChoice[i]==1 && bChoice[i]==0  ||aChoice[i]==2 && bChoice[i]==1 ||aChoice[i]==0 && bChoice[i]==2)
        {
            scoreOfAlice += (numberOfGames-i)/numOfChoices+1;
        }
        if (aChoice[i]==0 && bChoice[i]==1 ||aChoice[i]==1 && bChoice[i]==2 ||aChoice[i]==2 && bChoice[i]==0)
        {
            scoreOfBob += (numberOfGames-i)/numOfChoices+1;
        }
    }
    cout <<"Score of Alice is : "<<scoreOfAlice<<endl;
    cout<<"Score of Bob is : "<<scoreOfBob<< endl;
}
int main()
{
//Alice will choose number aChoice in the first game
//and Bob will choose bChoice in the first game.
    cout<<"Enter number of games : ";
    cin >> numberOfGames;
    cout<<"Enter Alice choice number : ";
    cin >> aChoice[1] ;
    cout<<"Enter Bob choice number : ";
    cin>> bChoice[1];
    aChoice[1]--, bChoice[1]--;//to treat first index in  array = 0
    //enter Alice choices
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cin >> Alice[i][j];
        }
    }
    //enter Bob choices
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cin >> Bob[i][j];
        }
    }
    calCycleOccurrence[ aChoice[1] ][ bChoice[1] ] = 1;
    Choices();
    calculateScore();
}
