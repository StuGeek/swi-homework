---
title: "用伪代码描述算法/07-作业7"
date: 2020-10-13T09:12:33-04:00
draft: false
tags: []
---

1、阅读 Pseudocode Standard。（答案可以打印）

1）用伪代码描述将十进制转换成16进制的方法

    IF the dec_num is 0
        The hex_num is 0
    END IF
    IF the dec_num  is less than 0
        Compute the dec_num as its opposite number
        Set the first character of hex_num to '-'
    END IF
    WHILE the dec_num is larger than 0
        Compute the x as dec_num % 16
        Set the last character of hex_num to the corresponding character of x
        Compute the dec_num as dec_num / 1
    END WHILE
    Swap the character except when the first character is '-'
    RETURN the hex_num

2）C语言实现（先用注释写好算法，然后翻译）

    char *DecToHex(int dec_num){
        char *hex_num = (char *)malloc(1000 * sizeof(char));
        int size = 0;
        //IF the dec_num is 0
        if (dec_num == 0){
            //The hex_num is 0
            hex_num[size++] = '0';
        }//END IF
        //IF the dec_num  is less than 0
        if (dec_num < 0){
            //Compute the dec_num as its opposite number
            dec_num = -dec_num;
            //Set the first character of hex_num to '-'
            hex_num[size++] = '-';
        }//END IF
        //WHILE the dec_num is larger than 0
        while(dec_num > 0){
            //Compute the x as dec_num % 16
            int x = dec_num % 16;
            //IF the remainder of dec_num and 16 is larger than 9
            if (x > 9){
                //Set the last character of hex_num to the corresponding character of x
                hex_num[size++] = x - 10 + 'a';
            }//END IF
            else{
                hex_num[size++] = x + '0';
            }
            //Compute the dec_num as dec_num / 16
            dec_num /= 16;
        }//END WHILE
        int index = size - 1;
        //Swap the character except when the first character is '-'
        for (int i = 0; i < (size + 1) / 2; ++i){
            if (hex_num[i] == '-'){
                index++;
                continue;
            }
            char c = hex_num[i];
            hex_num[i] = hex_num[index - i];
            hex_num[index - i] = c;
        }
        hex_num[size] = '\0';
        //RETURN the hex_num
        return hex_num;
    }

3）使用 -1, 0, 1, 15, 26，3265 作为输入测试你的程序

输入为-1时，输出为-1

输入为0时，输出为0

输入为1时，输出为1

输入为15时，输出为f

输入为26时，输出为1a

输入为3265时，输出为cc1

2、名词解释与对比

1）Top-down design

A top-down approach (also known as stepwise design and in some cases used as a synonym of decomposition) is essentially the breaking down of a system to gain insight into its compositional sub-systems in a reverse engineering fashion. In a top-down approach an overview of the system is formulated, specifying, but not detailing, any first-level subsystems. Each subsystem is then refined in yet greater detail, sometimes in many additional subsystem levels, until the entire specification is reduced to base elements.

自顶向下的方法（也称为逐步设计）本质上是分解系统，以便以逆向工程的方式深入了解其组成的子系统。在自顶向下的方法中，系统的概述被制定出来，指定但不详细说明任何一级子系统。然后对每个子系统进行更详细的细化，有时在许多额外的子系统级别上，直到整个规范被简化为基本元素。

2） Work breakdown structure (WBS)

A work-breakdown structure (WBS) in project management and systems engineering, is a deliverable-oriented breakdown of a project into smaller components. A work breakdown structure is a key project deliverable that organizes the team's work into manageable sections. The Project Management Body of Knowledge (PMBOK 5) defines the work-breakdown structure as a "hierarchical decomposition of the total scope of work to be carried out by the project team to accomplish the project objectives and create the required deliverables."

在项目管理和系统工程中，工作分解结构（WBS）是一种面向可交付成果的将项目分解成更小的部分的结构。工作分解结构是一个关键的项目可交付成果，它将团队的工作组织成可管理的部分。项目管理知识体系（PMBOK 5）将工作分解结构定义为“项目团队为完成项目目标和创建所需交付成果而执行的全部工作范围的分层分解。”

3）简述管理学 WBS 与 信息学Top-down设计 的异同

相同之处：

管理学WBS和信息学Top-down都是将问题分解成几个小的部分，从更加容易入手的小问题开始解决，从而解决问题。

不同之处：

管理学WBS是按照类型来划分小的部分，依照目标将问题分成几个部分，各个部分联系十分紧密，相互合作从而达到目标。

信息学Top-down是将问题分成几个小的可以实现的目标，分别实现这些几个小的目标，几个小部分之间不一定要有联系，一步一步实现从而达到目标。

3、仔细观察您洗衣机的运作过程，运用Top-down设计方法和Pseudocode 描述洗衣机控制程序。假设洗衣机可执行的基本操作如下：

water_in_switch(open_close) // open 打开上水开关，close关闭

water_out_switch(open_close) // open 打开排水开关，close关闭

get_water_volume() //返回洗衣机内部水的高度

motor_run(direction) // 电机转动。left左转，right右转，stop停

time_counter() // 返回当前时间计数，以秒为单位

halt(returncode) //停机，success 成功 failure 失败

1）请使用伪代码分解“正常洗衣”程序的大步骤。包括注水、浸泡等

    选择洗衣服的时间、浸泡时间、水位高度
    打开上水开关
    注水至设定水位高度，然后关闭上水开关
    浸泡直到达到浸泡时间
    在一个洗衣周期内，电机左转3次，右转3次，时间增加1分钟
    当时间到达洗衣时间时，电机停止转动
    打开排水开关
    排水至水位为0时，关闭排水开关
    如果都完成，停机成功，否则停机失败

2）进一步用基本操作、控制语句（IF、FOR、WHILE等）、变量与表达式，写出每个步骤的伪代码

    BEGIN
        READ washing_time, soaking_time, water_line
        SET water_level tp 0
        water_in_switch(open)
        WHILE get_water_volume() <  water_line
            INCREASEMENT water_level
        ENDWHILE
        water_in_switch(close)
        SET time to 0
        WHILE time_counter() < soaking_time
            INCREASEMENT time
        ENDWHILE
        SET time to 0
        WHILE time_counter() < wash_time
            motorrun(left)
            motorrun(left)
            motorrun(left)
            motorrun(right)
            motorrun(right)
            motorrun(right)
            COMPUTE time as time + 60
        ENDWHILE
        motorrun(stop)
        water_out_switch(open)
        WHILE get_water_volume() >  0
            DECREASEMENT water_level
        ENDWHILE
        water_out_switch(close)
        halt(success)
    EXCEPTION
        halt(failure)

3）根据你的实践，请分析“正常洗衣”与“快速洗衣”在用户目标和程序上的异同。

答：“正常洗衣”和“快速洗衣”都需要经过洗衣服的基本步骤，但是“快速洗衣”比“正常洗衣”少了浸泡的步骤。

你认为是否存在改进（创新）空间，简单说明你的改进意见？

答：“快速洗衣”时可以加大电机的转速，从而达到更好的洗衣效果。

4）通过步骤3），提取一些共性功能模块（函数），简化“正常洗衣”程序，使程序变得更利于人类理解和修改维护。例如：

wait(time) //等待指定的时间；

注水(volume,timeout) //在指定时间内完成注水，否则停机；

排水(timeout)。 等子程序

    BEGIN
        READ washing_time, volume_time, soaking_time, water_line
        SET water_level tp 0
        water_in_switch(open)
        注水(water_line, volume_time)
        water_in_switch(close)
        wait(soaking_time)
        SET time to 0
        WHILE time_counter() < wash_time
            motorrun(left)
            motorrun(left)
            motorrun(left)
            motorrun(right)
            motorrun(right)
            motorrun(right)
            COMPUTE time as time + 60
        ENDWHILE
        motorrun(stop)
        water_out_switch(open)
        排水(volume_time)
        water_out_switch(close)
        halt(success)
    EXCEPTION
        halt(failure)