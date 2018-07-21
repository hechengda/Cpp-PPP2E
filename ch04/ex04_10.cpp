// Bjarne Stroustrup 4/4/2009
// Chapter 4 Exercise 10

#include "std_lib_facilities.h"

/*
Somehow, we have to get the computer to be a bit unpredicatble.
There are many ways of doing that. All of the good ones involves random numbers,
but here I'll just do somthing simple that does not use any advanced programming.

The computer will play based on a series of (Fibbonacci) numbers that we generate using the
function next_play().

To avoid having the computer always play the same game we ask the player to enter a "seed";
different seeds can give different games.
*/

int v1 = 1;
int v2 = 2;

// generate the next element of a (Fibbonacci) series
int fib()
{
    int s = v1+v2;
    if (s<=0) {     // maybe overflow
        s = 1;
    }
    v1 = v2;
    v2 = s;
    return s;
}

// use the seed to choose where in the sequence the game starts
void generate(int seed)
{
    if (!seed) {    // don't bother: use the default
        return;
    }
    if (seed<0) {   // don't want a negative number
        seed = -seed;
    }
    seed %= 10; // don't want a number larger than 9

    for (int i = 0; i!=seed; ++i) { // move seed steps forward
        fib();
    }
}

// generate a reasonably obscure sequence of 0s, 1s, and 2s
int next_play()
{
    return fib()%3; // we are only interested in a value 0, 1, or 2
}

int main()
try {
    cout << "enter an integer \"seed\" to help me play: ";
    int seed = 0;
    cin>>seed;
    generate(seed); // get the computer ready to play

    // let's keep track of who's winning:
    int usr_score = 0; // user's score
    int cpt_score = 0; // computer's score
    int draws = 0;  // number of draws/ties
    cout<<"enter \"rock\", \"paper\", or \"scissors\"\n"
        <<"(I'll do the same and promises not to cheat by peeping at your input): ";

    // we'll as long as we get "good" input and then stop
    // the computer prefers numbers, so convert string representations to numbers
    // we prefer strings (except when wet ype), so convert abbreviations to full words
    for (string su; cin>>su;) {
        int iu = 0;

        if (su=="scissors" || su=="s") {
            iu = 0;
            su = "scissors";
        }
        else if (su=="rock" || su=="r") {
            iu = 1;
            su = "rock";
        }
        else if (su=="paper" || su=="p") {
            iu = 2;
            su = "paper";
        }
        else {
            error("sorry: bad operator: ", su);
        }
        int ic = next_play();
        string sc;  // computers play

        switch (ic) {    // we prefer strings, so convert numeric representations to strings
            case 0:
                sc = "scissors";
                break;
            case 1:
                sc = "rock";
                break;
            case 2:
                sc = "paper";
                break;
            default:
                break;
        }
        if (iu==ic) {
            cout << "a draw!\n";
            ++draws;
        }
        else {
            string res = "I win!";

            if (ic==0 && iu==1  // rock beats sissors
                || ic==1 && iu==2   // paper beats rock
                || ic==2 && iu==0) {    // scissors beat paper
                res = "You win!";
                ++usr_score;
            }
            else {
                ++cpt_score;
            }
            cout<<"you said \""<<su<<"\" I said \""<<sc<<"\": "<<res;
            cout<<" score: you=="<<usr_score<<" me=="<<cpt_score<<" same=="<<draws<<'\n';
        }
        cout<<"Please try again: ";
    }
    cout<<"exit because of bad input\n";
    return 0;
}
catch (runtime_error e) {   // this code is to produce error messages; it will be described in Chapter 5
    cout<<e.what()<<'\n';
    return 1;
}


/*
Did you have trouble remembering that
0 means "scissors"
1 means "rock"
2 means "paper"
?

I did. We could have avoided most of the use of numbers. Alternatively, we could have introduced
synbolic names for the numbers 0, 1, 2 - we'll get to that in chapters 7 and 8.
*/