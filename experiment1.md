---
title: "使用 Hugo 构建作业博客"
date: 2020-09-10T10:58:08-04:00
draft: false
tags: []
---

# 使用 Hugo 构建作业博客

## 一、下载Hugo

Hugo是一种由Go语言实现的静态网站生成器，利用Hugo我们可以快速搭建网站。

进入Hugo官网 https://gohugo.io/ 下载Hugo

安装完成后，打开cmd命令提示符窗口，输入

    hugo version

如果显示版本号，如图 
![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/1.png)
则表示安装成功。

## 二、建立网站

打开cmd命令提示符窗口，输入命令

    hugo new site your-website
    cd your-website

![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/2.png)

此时新建了一个你的网站的文件夹。

## 三、引入主题

为Hugo选择主题，例如在Hugo网站QuickSstart中所选定的Ananke Gohugo Theme主题，https://themes.gohugo.io/gohugo-theme-ananke/ 
![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/3.png)按照Quick Start的教程，完成主题的安装，在your-website目录下，在cmd窗口输入

    git init
    git submodule add https://github.com/budparr/gohugo-theme-ananke.git themes/ananke

等待安装成功后，在your-website的文件夹目录下的themes文件中，可看见ananke主题的文件夹。

将ananke文件夹中的exampleSite文件夹目录下的config.toml文件复制到到your-website文件夹的目录下，覆盖your-website文件夹下的config.toml文件，将ananke文件夹archetypes文件夹中的default.md文件覆盖your-website文件夹目录下原有的default.md文件，

在your-website目录下，在cmd窗口输入

    hugo --theme=ananke
    hugo server -D --theme=ananke

启动hugo的本地服务器，在生成的网址中可看见你的主题的效果

在your-website目录下，输入

    hugo new posts/my-first-post.md

创建你的第一个博客文件，在md文件中可完成你的文章。在写好文章后，要将文章的draft属性改为false，这样才能被网站编译

![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/4.png)


## 四、在Gitee上建立你的仓库

在Gitee上点击右上角的新建仓库
![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/5.jpg)

将是否开源设为“公开”，将语言设为HTML/CSS，建立新的仓库
![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/6.jpg)

在本地新建一个名为test的仓库，用git打开这个文件夹，按照Gitee网站上的提示完成全局变量设置，输入以下代码，完成初始化

    git init
    touch README.md
    git add README.md
    git commit -m "first commit"
    git remote add origin https://gitee.com/stugeek/test.git
    git push -u origin master


## 五、在Gitee上生成你的网站

在你的your-website目录下的post文件夹中用md文件写好你的文章之后，在your-website目录下打开cmd命令提示符窗口，输入

    hugo

此时在your-website文件夹目录下会出现一个名为public的文件夹，将这个文件夹中的内容复制到你的test仓库中，在VSCode中保存你的更改
![](http://stugeek.gitee.io/stu-geek/posts/experiment1-image/7.png)

再点击推送将内容发布到Gitee网站上，在Gitee网站你创建的仓库中点击service，再点击里面的Gitee Page服务，点击更新在Gitee上生成你的博客网站，点击生成的网站，就可以建立你的网站了。










