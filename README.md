#### 这里记录我的移动端开发搜集的坑和技巧

> 案例一，移动端普见的300ms延迟带来的各种为题：

1. [a标签的href属性与click事件的烦恼](http://hcysun.me/2015/11/26/a%E6%A0%87%E7%AD%BE%E7%9A%84href%E5%B1%9E%E6%80%A7%E4%B8%8Eclick%E4%BA%8B%E4%BB%B6%E7%9A%84%E7%83%A6%E6%81%BC/)
   本文讲述的是核心就是当点击浏览器a标签的时候，浏览器的默认机制如下：
    -   1.1 触发a的click事件
    -   1.2 读取href属性的值
    -   1.3 如果是URI则跳转
    -   1.4 如果是javascript代码则执行该代码

2. [用 iOS 在手Q阅读书友交流区发表书评时，光标点击总是不好定位到正确的位置](https://www.cnblogs.com/vajoy/p/5522114.html)
    -   2.1 额外总结：对于自己发现的奇怪现象，又觉得无法定位的时候，就去对比相同结构的页面，看看他们的页面有没有相同的问题。
    -   2.2 关于fastclick的源码阅读，由于里面有很多的hack，可能阻碍阅读，建议大致知道先跳过。 主流程 touchstart => toutchend => e.preventDefault , dispatchEvent => click。 注意有个preventDefault，他其实是会阻止原生click、mousemove、fouce这样的事件,然后自己触发自定义click事件，这样就避免了300ms延迟。

3. [移动端的touch click事件的理解+点透](https://www.jianshu.com/p/dc3bceb10dbb)
   总结起来就是:
    -   3.1 当一个用户在点击屏幕的时候，系统会触发touch事件和click事件，touch事件优先处理，touch事件经过 捕获，处理, 冒泡 一系列流程处理完成后， 才回去触发click事件
    -   3.2 当手指触摸到屏幕的时候，系统生成两个事件，一个是touch 一个是click，touch先执行，touch执行完成后，A从文档树上面消失了，而且由于移动端click还有延迟200-300ms的关系，当系统要触发click的时候，发现在用户点击的位置上面，目前离用户最近的元素是B，所以就直接把click事件作用在B元素上面了.
4. [touch click mouse事件](https://www.cnblogs.com/irelands/p/3433628.html)


> 案例二，移动端适配问题：

1. 