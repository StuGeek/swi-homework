---
title: "03-作业3"
date: 2020-09-21T21:12:33-04:00
draft: false
tags: []
---

## Part 1
### 题目：Write out variables x, y and z in binary code 
1) int8_t x = 67; int8_t y = -7; int8_t z = y - x;
2) int8_t x = 0xd3;
3) uint8_t = 0xd3;
4) int8_t x = 127; int8_t y = -7; int8_t z = y – x;
5) float x = 1.125; 
6) float x = 23.0;
7) float x = 0.45;
上述代码中，哪些出现溢出错误，哪些出现精度误差。

<strong>解答：</strong>

1、解：

x=01000011（8位有符号二进制数表示）， y=11111001（8位有符号二进制数表示）
z=-74=10110110（8位有符号二进制数表示）
无错误

2、解：

x=0xd3=211=011010011（9位有符号二进制数表示）
8位有符号数表示范围为[-128,127]
发生溢出错误

3、解：

x=0xd3=211=11010011（9位有符号二进制数表示）
8位无符号数表示范围为[0,255]
无错误

4、解：

x=127=01111111（8位有符号二进制数表示），y=-7=11111001（8位有符号二进制数表示）
z=-134=101111010（9位有符号二进制数表示）
发生溢出错误

5、解：

x=1.125=1.001
无误差

6、解：

x=23.0=10111.0
无误差

7、解：

x=0.45=0.011100110011···
出现精度误差

---
## Part 2 

### 使用维基百科，解释以下概念。
1)Method of complements

2)Byte

3)Integer (computer science)

4)Floating point

<strong>（1）、Method of complements：</strong>

In mathematics and computing, the method of complements is a technique to encode a symmetric range of positive and negative integers in a way that they can use the same algorithm (hardware) for addition throughout the whole range. 

<strong>（2）、Byte：</strong>

The byte is a unit of digital information that most commonly consists of eight bits. Historically, the byte was the number of bits used to encode a single character of text in a computer and for this reason it is the smallest addressable unit of memory in many computer architectures.

<strong>（3）、Integer (computer science)：</strong>

In computer science, an integer is a datum of integral data type, a data type that represents some range of mathematical integers. Integral data types may be of different sizes and may or may not be allowed to contain negative values.

<strong>（4）、Floating point：</strong>

In computing, floating-point arithmetic (FP) is arithmetic using formulaic representation of real numbers as an approximation to support a trade-off between range and precision.
<br/>

### 仔细阅读” Method of complements”的内容，你将注意到nines‘ complement in the decimal 和 ones’ complement in binary 等概念. 
1)请证明：二进制的负数（two‘s complement of X）等于 X 的 ones’ complement ＋ 1（即，X每位求反加1）

2)Int8_t x = - 017; 请用8进制描述变量 x。在c中017即(017)8

(1)、解：

（a）、对于一个n位的二进制负整数

对于一个n位的二进制负整数，它的补码的定义为：

>[X]补=2的n次方＋X MOD (2的n次方)……（1）


对于一个n位的二进制负整数，它的反码的定义如下：

>[X]反=(2的n次方－1)＋X MOD (2的n次方－1)……（2）


　由（2）式，[X]反=(2的n次方－1)＋X，得：

　X=[X]反－2的n次方＋1

　将其代入（1）式，有

　[X]补=2的n次方＋X

　=2n＋[X]反－2n＋1

　=[X]反＋1

所以，对于一个n位的二进制负整数，其补码等于反码加1成立

（b）、对于一个n位的二进制负小数

对于一个n位的二进制负小数，它的补码的定义如下：

>[X]补=2＋X MOD 2……（3）


对于一个n位的二进制负小数，它的反码的定义如下：

>[X]反=2－2的－(n－1)次方＋X MOD (2－2的－(n－1)次方……（4）


由（4）式，[X]反=2－2的－(n－1)次方＋X，得：

X=[X]反－2＋2的－(n－1)次方

将其代入（3）式，有

[X]补=2＋X

=2＋[X]反－2＋2的－(n－1)次方

=[X]反＋2的－(n－1)次方

上式中，2的－(n－1)次方的二进制即为小数点后第n－1位为1，其余位为0，小数点后第n－1位为1，即n位定点小数最右最末的一位为1。因此上式：[X]补=[X]反＋2的－(n－1)次方，也就是X的补码等于其反码与末位加1之和）

所以，对于一个n位的二进制负小数，其补码等于反码加1成立

综上所述，二进制的负数（two‘s complement of X）等于 X 的 ones’ complement ＋ 1

（2）、
x=-017=-15=11110001=361
<br/>
<br/>

### 阅读维基百科” Two‘s complement”的内容，特别是Sign extension小节内容。
1)C程序：int8_t x = -0x1f; int y = x; 请用16进制描述变量 x 和 y，并说明 int y = x 的计算过程。

2)请用数学证明，为什么可以这么计算。

(1)、

解：

x=-0x1f=-31=11100001=e1
int类型在C中占4个字节，32位，
所以将8位的x进行符号扩展到32位，即在x的前面加上24个1，即得到y,
y=x=11111111111111111111111111100001=ffffffe1

(2)、

解：假设C为n位二进制数，d>n,ai=0或1,

(a)、当C为正数时，

![](http://stugeek.gitee.io/stu-geek/post/homework3-image/1.png)

所以，当n位二进制数C为正数时，在其第n位左边补0可以实现符号扩展

(b)、当C为负数时，

![](http://stugeek.gitee.io/stu-geek/post/homework3-image/2.png)

所以，当n位二进制数C为负数时，在其第n位左边补1可以实现符号扩展
<br/>
<br/>

### 阅读维基百科” Floating point”的内容，
1) NaN 是什么？
   
答：IEEE 754指定一个特殊值“ Not a Number”（NaN）作为某些“无效”操作（例如0/0，∞×0或sqrt（-1））的结果返回。大多数涉及NaN的操作都将导致NaN，尽管对于任何给定的浮点值都会给出某些已定义结果的函数也将对NaN这样做，例如NaN ^ 0 = 1。