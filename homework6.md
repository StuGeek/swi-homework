---
title: "06-作业6"
date: 2020-10-06T09:12:33-04:00
draft: false
tags: []
---

## Part 1

1、According to the von Neumann architecture, List basic parts of a computer.

答：运算器，存储器，控制器，输入设备，输出设备。

2、A computer has 64 MB (megabytes) of memory. How many bits are needed to address any single byte in memory?

解：

2^16=65536=64MB，

所以用16位

3、List basic parts of a CPU, include cache or not?

答：控制部件（控制单元），算术逻辑部件（运算单元），存储单元，存储单元中包括缓存。

4、What mean secondary storage. List some on your PC.

答：辅助存储设备，U盘，移动硬盘，网络硬盘，光盘。

5、使用维基百科，解释以下概念：
CPU、RAM、ROM、Bus (computing)、Parallel Computing

<strong>CPU：</strong>

A central processing unit (CPU), also called a central processor or main processor, is the electronic circuitry within a computer that executes instructions that make up a computer program.

<strong>RAM：</strong>

Random-access memory (RAM /ræm/) is a form of computer memory that can be read and changed in any order, typically used to store working data and machine code.

<strong>ROM：</strong>

Read-only memory (ROM) is a type of non-volatile memory used in computers and other electronic devices.

<strong>Bus (computing)：</strong>

In computer architecture, a bus(a contraction of the Latin omnibus[citation needed], and historically also called data highway) is a communication system that transfers data between components inside a computer, or between computers.

<strong>Parallel Computing：</strong>

Parallel computing is a type of computation where many calculations or the execution of processes are carried out simultaneously.


6、写一段文字，简单解释“云计算（cloud computing）"

答：云计算是分布式计算的一种，其通过将许多数据的计算和处理程序分解为无数个小程序，通过多台服务器系统处理分析这些小程序再进行合并从而得到结果。

7、小孙买了计算机主板，说明书表明“支持双通道DDR3-1333内存，最大支持16G” 

1）DDR3内存，“3”和“1333”的含义是什么？

答：“3”是第三代内存的意思，“1333”是内存分频率，默认的工作频率是1333MHz。

2）小孙买8G DDR3-1600的内存能提高性能吗？

答：可以。

3）小孙买4G*2 DDR3-1333的内存能提高性能吗？

答：不可以。

4）16G需要多少位地址？

答：34位。

备注，维基百科（中文）“DDR3 SDRAM”

## Part 2

1、Program with machine language according to the following c.

int_8 a = 1; 

int_8 c = a + 3; 

1）Write your assembly code & machine code

assembly code:

LOD #1

STO X

LOD X

ADD #3

STO Y

HLT

machine code:

00010100 00000001

00000101 10000001

00000100 10000001

00010000 00000011

00000101 10000000
    

2）Explain machine code execution with the fetch-decode-execute cycle

![](http://stugeek.gitee.io/stu-geek/posts/homework6-image/1.png)

答：Main memory –> Fetch instruction –> Decode instruction –> Registers –> Get data –> Execute the instruction –> Main memory。

3）Explain functions about IR, PC, ACC registers in a CPU

答：

IR是指令寄存器，用来保存当前执行的指令

PC是程序计数器，存放当前执行指令的下一条指令在内存中的地址

ACC是累加寄存器，当算术逻辑单元执行运算时，为其暂时存放运算结果

4）Explain physical meaning about vars a & c in a machine

答：就是将a和c的每一位同时为1（高电平）的置为1（高电平），否则置为0（低电平）。

2、简答题

1）What are stored in memory?

答：数据以及指令。

2）Can a data or a instruction stored in the same place?

答：可以。

3） Explain Instruction Format with example instructions.

![](http://stugeek.gitee.io/stu-geek/posts/homework6-image/2.png)

![](http://stugeek.gitee.io/stu-geek/posts/homework6-image/2.png)

3、解释以下词汇

1）汇编语言（Assembly Language） 

汇编语言（Assembly Language）是任何一种用于电子计算机、微处理器、微控制器或其他可编程器件的低级语言，亦称为符号语言。在汇编语言中，用助记符代替机器指令的操作码，用地址符号或标号代替指令或操作数的地址。在不同的设备中，汇编语言对应着不同的机器语言指令集，通过汇编过程转换成机器指令。特定的汇编语言和特定的机器语言指令集是一一对应的，不同平台之间不可直接移植。

2）编译（Compiler） 

编译就是把高级语言变成计算机可以识别的2进制语言，计算机只认识1和0，编译程序把人们熟悉的语言换成2进制的语言。

3）命令式语言（Imperative programming）

命令式程序设计语言是基于动作的语言，以冯诺依曼计算机体系结构为背景。机器语言及汇编语言是最早的命令式语言。在这种语言中，计算机被看做是动作的序列，程序就是用语言提供的操作命令书写的一个操作序列。用命令式程序设计语言编写程序，就是描述解题过程中每一步的过程，程序的运行过程就是问题的求解过程，因此也称为过程式语言。Fortran、ALGOL、COBOL、C、Ada、Pascal等都是命令式程序设计语言。

4）函数编程语言（Functional programming）

函数式编程或称函数程序设计，又称泛函编程，是一种编程典范，它将计算机运算视为数学上的函数计算，并且避免使用程序状态以及易变对象。比起指令式编程，函数式编程更加强调程序执行的结果而非执行的过程，倡导利用若干简单的执行单元让计算结果不断渐进，逐层推导复杂的运算，而不是设计一个复杂的执行过程。
 
5）过程式编程（Procedural programming）

过程式编程是一种以过程为中心的编程思想。就是分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现，使用的时候一个一个依次调用就可以了。可以说面向过程是一种基础的方法。它考虑的是实际地实现。一般的面向过程是从上往下步步求精，所以面向过程最重要的是模块化的思想方法。