#include "playscr.h"
#include "ui_playscr.h"

void playScr::calculate()
{
    for (int i = 0; i < 10; i++)  //初始化数组
        for (int j = 0; j < 10; j++)
          {
            Initial[i][j] = 0;
            Answer[i][j]=0;
          }
    for (int i = 1; i < 10; i++)  //初始化第一行
        Initial[1][i] = i;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));  //初始化随机数种子
    std::random_shuffle(&Initial[1][1], &Initial[1][10]);  //使用函数对第一行进行随机处理
    check(2, 1);  //从第二行第一列开始进行深度搜索
    std::cout<<"Initial:"<< std::endl;  //输出搜索结果，debug用
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
            std::cout << Initial[i][j] << '\t';
         std::cout << std::endl;
    }
    ans(diffnum);  //随机生成答案数组
    std::cout<<"Initial:"<< std::endl;
    for (int i = 1; i < 10; i++)  //输出生成答案后数独结果，debug用
    {
        for (int j = 1; j < 10; j++)
             std::cout << Initial[i][j] << '\t';
         std::cout <<  std::endl;
    }
    std::cout<<"Answer:"<< std::endl;
    for (int i = 1; i < 10; i++)  //输出答案数组，debug用
    {
        for (int j = 1; j < 10; j++)
             std::cout << Answer[i][j] << '\t';
         std::cout <<  std::endl;
    }
}

void playScr::ans(int num)  //生成随机答案数独
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));  //qt方法生成随机数种子
    while(num)  //生成num个数的缺空
    {
        static int i=1;  //成功生成的计数器
        int x=rand()%9+1;
        int y=rand()%9+1;  //随机生成坐标
        if(Initial[x][y])  //判断该点可否被生成
        {
            Answer[x][y]=Initial[x][y];
            Initial[x][y] = 0;
            i++;
            num--;
        }  //执行生成操作
    }
}

bool playScr::check(int x, int y)  //生成一个完整数独的深度搜索函数
{
    if (x > 9 || y > 9)  //如果行列均大于9，说明搜索结束，返回真
        return true;
    for (int k = 1; k < 10; k++)  //对每一个格子，从1开始检测
    {
        bool can = true;  //布尔变量表示该格子能否被生成
        for (int m = 1; m < x; m++)  //检测一列是否有重复
            if (Initial[m][y] == k)
            {
                can = false;
                break;
            }
        if (can)
            for (int n = 1; n < y; n++)  //检测一行是否有重复
                if (Initial[x][n] == k)
                {
                    can = false;
                    break;
                }
        if (can)
        {
            int up = (x / 3) * 3 + 3;
            int down = (y / 3) * 3 + 3;  //计算宫格
            if (x % 3 == 0)
                up = x;
            if (y % 3 == 0)
                down = y;
            for (int m = up - 2; m <= up; m++)  //检测宫格是否有重复
            {
                if (can == false)
                    break;
                for (int n = down - 2; n <= down; n++)
                {
                    if (Initial[m][n] == k)
                    {
                        can = false;
                        break;
                    }
                }
            }


        }
        if (can)
        {
            Initial[x][y] = k;  //生成本格，搜索下一层
            if (x < 9)
            {
                if (check(x + 1, y))  //搜索本行下一列
                    return true;
            }
            else
            {
                if (y < 9)
                {
                    if (check(1, y + 1))  //搜索下一列第一行
                        return true;
                }
                else
                    return true;
            }
        }
        Initial[x][y] = 0;  //如果搜索失败，重新归0该格子
    }
    return false;
}
