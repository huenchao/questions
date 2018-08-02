#### 这里记录我的移动端开发搜集的坑和技巧

> 案例一，移动端普见的300ms延迟带来的各种为题：

1. [a标签的href属性与click事件的烦恼](http://hcysun.me/2015/11/26/a%E6%A0%87%E7%AD%BE%E7%9A%84href%E5%B1%9E%E6%80%A7%E4%B8%8Eclick%E4%BA%8B%E4%BB%B6%E7%9A%84%E7%83%A6%E6%81%BC/)
   本文讲述的是核心就是当点击浏览器a标签的时候，浏览器的默认机制如下：
    -   1.1 触发a的click事件
    -   1.2 读取href属性的值
    -   1.3 如果是URI则跳转
    -   1.4 如果是javascript代码则执行该代码

2. [用 iOS 在手Q阅读书友交流区发表书评时，光标点击总是不好定位到正确的位置](https://www.cnblogs.com/vajoy/p/5522114.html)