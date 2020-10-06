---
title: "硬件编程--电路与二进制运算"
date: 2020-10-05T10:58:08-04:00
draft: false
tags: []
---

# 硬件编程--电路与二进制运算

## 任务 1：建立一个简单电路

（1） 设计与门验证电路

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/1.png)

（2） 画真值表验证与门功能

当In A = 0， IN B = 0时，Out = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/2.png)

当In A = 0， IN B = 1时，Out = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/3.png)

当In A = 1， IN B = 0时，Out = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/4.png)

当In A = 1， IN B = 1时，Out = 1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/5.png)

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/23.png)

（3）选做题：

如何用 XOR 门作非门

答：将其中一个输入与一个高电平相连。

串联、并联三极管，结果是什么门

答：串联三极管结果是与门，并联三极管结果是或门。

## 任务 2：验证电路等价

（1）分别建立电路 A（B+C）和 AB+AC 在一个界面上。

用 A，B，C 用三个开关控制输入，用两个 LED 表示输出。

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/6.png)

（2）并枚举所有可能输入，用真值表记录结果。

设Out1=A(B+C)，Out2=AB+AC

当In A = 0， IN B = 0, IN C = 0时，Out1 = 0, Out2 = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/7.png)

当In A = 0， IN B = 0, IN C = 1时，Out1 = 0, Out2 = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/8.png)

当In A = 0， IN B = 1, IN C = 0时，Out1 = 0, Out2 = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/9.png)

当In A = 0， IN B = 1, IN C = 1时，Out1 = 0, Out2 = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/10.png)

当In A = 1， IN B = 0, IN C = 0时，Out1 = 0, Out2 = 0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/11.png)

当In A = 1， IN B = 0, IN C = 1时，Out1 = 1, Out2 = 1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/12.png)

当In A = 1， IN B = 1, IN C = 0时，Out1 = 1, Out2 = 1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/13.png)

当In A = 1， IN B = 1, IN C = 1时，Out1 = 1, Out2 = 1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/14.png)

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/24.png)

## 任务 3：理解存储电路

（1）按课件 S-R latch 搭建电路，例如：

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/15.png)

（2）顺序按Set，Reset，并填写以下表格

一开始当~ Set=1，~ Reset=1时，Q(X)=0，~Q(Y)=1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/16.png)

接着当~ Set=0，~ Reset=1时，Q(X)=0，~Q(Y)=1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/17.png)

接着当~ Set=1，~ Reset=1时，Q(X)=0，~Q(Y)=1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/18.png)

接着当~ Set=1，~ Reset=0时，Q(X)=1，~Q(Y)=0
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/19.png)

最后当~ Set=1，~ Reset=1时，Q(X)=1，~Q(Y)=1
![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/20.png)

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/25.png)

## 任务 4：设计全加电路

全加器表达式：

Ci = AiBi + Ci-1(Ai+Bi)
Si = Ai ⊕ Bi ⊕ Ci-1

（1） 画出一位的全加电路 

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/21.png)

（2） 画出二位的全加电路

![](http://stugeek.gitee.io/stu-geek/posts/experiment3-image/22.png)