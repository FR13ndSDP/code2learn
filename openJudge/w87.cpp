/* 写一个程序完成以下命令：
new id ——新建一个指定编号为id的序列(id<10000)
add id num——向编号为id的序列加入整数num
merge id1 id2——合并序列id1和id2中的数，并将id2清空
unique id——去掉序列id中重复的元素 */

// IN:
// 16
// new 1
// new 2
// add 1 1
// add 1 2
// add 1 3
// add 2 1
// add 2 2
// add 2 3
// add 2 4
// out 1
// out 2
// merge 1 2
// out 1
// out 2
// unique 1
// out 1

// OUT:
// 1 2 3 
// 1 2 3 4
// 1 1 2 2 3 3 4

// 1 2 3 4

#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1,4,2,7,5};
    int i,j;

    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            // if (a[i]> a[j])
            // {
            //     int tmp = a[i];
            //     a[i] = a[j];
            //     a[j] = tmp;
            // }
            cout << a[i];
        }
        cout << endl;
    }
    // for (i=0; i<5; i++)
    // {
    //     cout << a[i] << endl;
    // }
    return 0;
}