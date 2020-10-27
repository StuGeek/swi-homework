---
title: "09-作业9"
date: 2020-10-27T09:12:33-04:00
draft: false
tags: []
---

1. Bubble Sort the list: 33, 56, 17, 8, 95, 22。Make sure the final result is
from small to large. Write out the list after the 2nd pass. (10 points)

(1)、33,56,17,8,95,22

(2)、33,17,8,56,22,95

(3)、17,8,33,22,56,95

(4)、8,17,22,33,56,95

所以在第二次排序后，数字序列为 17,8,33,22,56,95。

2. Give a sorted array as list={60,65,75,80,90,95}. Design an algorithm to
insert the value of x into the sorted array. Then test the algorithm with
value 50,67,99.

    将插入点加入到链表末尾
    WHILE 插入点的值小于前一个点的值
        将插入点和前一个点交换
    ENDWHILE

插入点的值为50时，最后list={50,60,65,75,80,90,95}

插入点的值为67时，最后list={60,65,67,75,80,90,95}

插入点的值为99时，最后list={60,65,75,80,90,95,99}

思考：为什么选择插入点在list头上、中间、尾巴上的三个数作为算法测试的数据，你能解释吗？

答：因为这是三种普遍情况，如果一个点要插入list中，只能从这三处插入。

3. What is the state of the stack after the following sequence of Push and
Pop operations?

Push “anne”; Push “get”; Push “your” ; Pop; Push “my” Push “gun”

答：

栈顶：gun

栈里的内容为：

 gun

 my

 get

 anne