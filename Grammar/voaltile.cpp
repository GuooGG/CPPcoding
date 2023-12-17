/**
 * @file voaltile.cpp
 * @author GGo
 * @brief volatile关键字的作用
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素更改，比如：操作系统、硬件或者其它线程等。遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问。声明时语法：int volatile vInt; 当要求使用 volatile 声明的变量的值的时候，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。而且读取的数据立刻被保存
 * 
 */

/**
 * @brief volatile指出vINT是随时可能会发生变化的，每次使用它时都必须从vINT的内存地址中读取
 * 用它声明的类型变量表示可以被某些编译器未知的因素更改，比如：操作系统、硬件或者其它线程等。
 */
volatile int vINT = 0;

int main(){
    return 0;
}