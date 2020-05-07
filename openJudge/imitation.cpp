#include <iostream>
using namespace std;

// name and HP in red sequence
int HP[5] = {0, 0, 0, 0, 0};
string name[5]= {"iceman", "lion", "wolf", "ninja", "dragon"};
//TODO: should be useful if expand complexity
/* class Soldier
{
    int hp_;
    int id_;

public:
    Soldier(int id, int type)
    {
        id_ = id;
        hp_ = HP[type];
    }
}; */

class Headquater
{
public:
    bool stopped_;                  // stop flag
    int power_;                     // total HP
    string color_;                  // which side in game
    int exist[5]; // number of exist soldier
    int turn;                       // turn of game
    int tot;
    Headquater() {}
    Headquater(string color, int power) : color_(color), power_(power)
    {
        stopped_ = 0;
        turn = -1; // in first turn , it will be set to 0, nexr turn ++
        for (int i=0;i<5;i++)
        {
            exist[i] = 0;
        }
        tot = 0;
    }
    bool summon(int type); //decide if a soldier is made
    bool summon_pre();     // make soldiers
    void stop(); // print stop message
}RED, BLUE;

class game
{
public:
    int time_;
    void modify()
    {
        time_++;
    }
    string show() // show time in 'xxx' format
    {
        string p = "";
        int x = time_;
        while (x)
        {
            p = char((x % 10) + '0') + p;
            x /= 10;
        }
        while (p.length() < 3)
            p = '0' + p;
        return p;
    }

    // decide if a new turn should go on
    void newturn()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 5) // no soldier to make
                RED.stop();
            else if (RED.summon_pre())
                break;
        }
        for (int i = 0; i < 6; i++)
        {
            if (i == 5)
                BLUE.stop();
            else if (BLUE.summon_pre())
                break;
        }
        modify();
    }
    void reset()
    {
        time_=0;
    }
}game;

void Headquater::stop()
{
    if (!stopped_)
        cout <<game.show()<<" "<< color_ << " headquarter stops making warriors\n";
    stopped_ = 1;
}

/* 
   color : red or blue
   type : [0-5] in red sequence
   tot : total number of soldiers made
   num : number of specific soldier type
*/
void printinfo(string color, int type, int tot, int num) 
{
    cout << game.show()<< ' '<< color <<' '<< name[type]<<' '<< tot << " born with strength "
    << HP[type]<< ","<< num << " "<<name[type] << " in "<< color << " headquarter\n";
}

bool Headquater::summon(int type)
{
    if (HP[type] <= power_)
    {
        exist[type] += 1; // update soldier number
        power_ -= HP[type]; // update headquater power 
        tot++;
        printinfo(color_, type, tot, exist[type]);
        return true;
    }
    else
    {
        return false; // stop make sign
    }
}

bool Headquater::summon_pre()
{
    turn ++;
    if (color_ == "red")
    {
        return summon(turn % 5); // run in red sequence
    }
    else
    {
        switch (turn % 5) //TODO: run in blue sequence, should be more elegent
        {
        case 0:
            return summon(1);
        case 1:
            return summon(4);
        case 2:
            return summon(3);
        case 3:
            return summon(0);
        case 4:
            return summon(2);
        }
    }
}



int main()
{
    int T,M;
    cin >> T;
    for (int i=1; i<=T; i++)
    {   
        game.reset();
        cout << "Case:"<< i<< endl;
        cin >> M;
        RED = Headquater("red", M);
        BLUE = Headquater("blue", M);
        cin >> HP[4]>>HP[3]>>HP[0]>>HP[1]>>HP[2];
        while (game.time_ < 10000)
            game.newturn();
    }
    return 0;
}