// Test_Lua.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//#include <lua.hpp>
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int swap(int* a,int* b)
{
    //(*a) += (*b);
    //(*b) = (*a) - (*b);
    //(*a) = (*a) - (*b);
}
void xx(int arr[],int low,int high)
{
    if (high <= low)
        return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        while (arr[++i] < key)
        {
            if (i == high)
            {
                break;
            }
        }
        while (arr[--j] > key)
        {
            if (j == low)
            {
                break;
            }
        }
        if (i >= j)break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    xx(arr,low,j-1);
    xx(arr,j+1,high);
}
int add(lua_State* L)
{
    //从lua状态机的栈中取出索引为1的int型数值
    //int x = luaL_checkint(L, 1);
    //从lua栈中取出索引为2的int型数值
    //int y = luaL_checkint(L, 2);
    //printf("result:%d + %d = %d\n", x, y, x + y);
    printf("result: + \n");
    return 1;

}

int main()
{
    int a[10] = {3,5,7,4,9,6,78,34,67,3435};
    xx(a,0,9);
    int tt = a[9];
    /*lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L."main.lua");
    lua_close(L);
    cin.get();
    return 0;*/
    lua_State* L = luaL_newstate();     //新建一个lua状态机
    luaL_openlibs(L);   //打开相关的库
    lua_pushcfunction(L, add);  //将c++函数add入栈
    lua_setglobal(L, "ADD");    //设置全局符号ADD
    //加载lua脚本文件，这里使用了需要执行的Lua脚本文件的绝对路径
    if (luaL_loadfile(L, "E:\\project_vs2019\\LUA\\Test_Lua\\test.lua"))
    {
        printf("error in load lua file.\n");
    }
    //执行一次脚本，生成function
    lua_pcall(L, 0, 0, 0);
    //将lua函数myfunction入栈
    lua_getglobal(L, "myfunction");
    //执行脚本，执行function
    lua_pcall(L, 0, 0, 0);

    printf("Lua is done.\n");
    getchar();
    return 0;
}


