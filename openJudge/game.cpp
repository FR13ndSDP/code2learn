#include <vector>
#include <iostream>
#include <map>
using namespace std;
int T, M;

map<string, int> HP;
class Samurai
{
    int hp;
    int id;

public:
    // 初始化
    Samurai(int _id, string type)
    {
        id = _id;
        hp = HP[type];
    }
};

class Headquarter
{
public:
    bool stoped;
    int hp;
    int summon_id;
    int Stot;
    string color;
    vector<Samurai> Sam;
    map<string, int> Snum;
    Headquarter() {}
    Headquarter(string _color, int _hp) : color(_color), hp(_hp)
    {
        stoped = 0;
        summon_id = -1;
        Stot = 0;
        Sam.clear();
        Snum.clear();
    }
    bool summon(string type);
    bool summon_pre();
    void stop();
} RED, BLUE;

class Game
{
public:
    int t;
    void reset()
    {
        t = 0;
    }
    void modify()
    {
        t++;
    }
    string show()
    {
        string p = "";
        int x = t;
        while (x)
        {
            p = char((x % 10) + '0') + p;
            x /= 10;
        }
        while (p.length() < 3)
            p = '0' + p;
        return p;
    }
    void new_turn()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 5)
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
} game;

void Headquarter::stop()
{
    if (!stoped)
        cout << game.show() << ' ' << color << " headquarter stops making warriors\n";
    stoped = 1;
}
void printinfo(string color, string type, int num, int tot)
{
    cout << game.show() << ' ' << color << ' ' << type << ' ' << tot << " born with strength " << HP[type] << ',' << num << ' ' << type << " in " << color << " headquarter\n";
}

bool Headquarter::summon(string type)
{
    if (HP[type] <= hp)
    {
        Samurai S = Samurai(summon_id, type);
        Sam.push_back(S);
        Snum[type]++;
        Stot++;
        printinfo(color, type, Snum[type], Stot);
        hp -= HP[type];
        return true;
    }
    else
        return false;
}

bool Headquarter::summon_pre()
{
    summon_id++;
    if (color == "red")
    {
        switch (summon_id % 5)
        {
        case 0:
            return summon("iceman");
        case 1:
            return summon("lion");
        case 2:
            return summon("wolf");
        case 3:
            return summon("ninja");
        case 4:
            return summon("dragon");
        }
    }
    else
    {
        switch (summon_id % 5)
        {
        case 0:
            return summon("lion");
        case 1:
            return summon("dragon");
        case 2:
            return summon("ninja");
        case 3:
            return summon("iceman");
        case 4:
            return summon("wolf");
        }
    }
}

int main()
{
    cin >> T;
    game.reset();
    cout << "Case:" << T << endl;
    cin >> M;
    RED = Headquarter("red", M);
    BLUE = Headquarter("blue", M);
    cin >> HP["dragon"] >> HP["ninja"] >> HP["iceman"] >> HP["lion"] >> HP["wolf"];
    while (game.t < 10000)
    game.new_turn();
    return 0;
}