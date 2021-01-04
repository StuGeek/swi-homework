---
title: "字符游戏-智能蛇"
date: 2021-01-03T09:12:33-04:00
draft: false
tags: []
---

# 实验报告

## 一、控制输入/输出设备

### 1、VT 100 终端标准
将sin-demo.c的代码复制到虚拟机ubuntu下运行，结果如下：

![](http://stugeek.gitee.io/stu-geek/posts/experiment9-image/1.png)

![](http://stugeek.gitee.io/stu-geek/posts/experiment9-image/2.png)

### 2、实现 kbhit()
将tty.c的代码复制到虚拟机ubuntu下，按照提示将原来贪吃蛇游戏中主函数外的代码放在文件的主函数外的指定位置，将原来贪吃蛇游戏中主函数内的代码放在文件的主函数内的指定位置，再将原来output函数内的system("cls");语句换成printf("\033[2J\n");，然后运行，发现不用每次输入wasd后都按下回车，直接输入后贪吃蛇就可以移动，结果如下：

![](http://stugeek.gitee.io/stu-geek/posts/experiment9-image/3.png)

![](http://stugeek.gitee.io/stu-geek/posts/experiment9-image/4.png)

## 二、编写智能算法
实现代码后，贪吃蛇可以自动寻找有食物的方向并移动，不需操作直到最后游戏结束。结果如下：

![](http://stugeek.gitee.io/stu-geek/posts/experiment9-image/5.png)

![](http://stugeek.gitee.io/stu-geek/posts/experiment9-image/6.png)

代码的Gitee网址：



