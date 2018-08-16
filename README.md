#### 这里记录我搜集的坑和技巧

> 案例一，移动端普见的300ms延迟带来的各种问题：

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

1. [一篇真正教会你开发移动端页面的文章(一)](http://hcysun.me/2015/10/16/%E4%B8%80%E7%AF%87%E7%9C%9F%E6%AD%A3%E6%95%99%E4%BC%9A%E4%BD%A0%E5%BC%80%E5%8F%91%E7%A7%BB%E5%8A%A8%E7%AB%AF%E9%A1%B5%E9%9D%A2%E7%9A%84%E6%96%87%E7%AB%A0(%E4%B8%80)/)
   -    1.1 dpr = 实际手机像素／device-width、缩放的原理是缩放css像素、html的width是基于布局视口(document.documentElement.clientWidth)的，所以html的100%的宽度就是基于它来计算的。（布局视口|document.documentElement.clientWidth、视觉视口、理想适口|screen.width).
   -    1.2 关于[h5移动端基本知识科普](https://github.com/riskers/blog/issues/17);
2. [一篇真正教会你开发移动端页面的文章(二)](http://hcysun.me/2015/10/19/%E4%B8%80%E7%AF%87%E7%9C%9F%E6%AD%A3%E6%95%99%E4%BC%9A%E4%BD%A0%E5%BC%80%E5%8F%91%E7%A7%BB%E5%8A%A8%E7%AB%AF%E9%A1%B5%E9%9D%A2%E7%9A%84%E6%96%87%E7%AB%A0-%E4%BA%8C/)   
   -    2.1 rem的使用、字体要用媒体查询、以100px的html font-size来设置rem方面计算。
3. 51信用卡移动端适配的参考（3.2）：
   -    3.1 [文档一](https://github.com/amfe/lib-flexible/blob/2.0/index.js):这个脚本设置了（1）1rem = documentElement.clientWidth / 10（这其实并不好，因为阅读过2. 文章，我们知道始终设置docEl的font-size为100px,会更好计算其他元素的rem值，也更准确！）。（2）detect 0.5px supports.
   -    3.2 [文档二](https://github.com/amfe/article/issues/17):这篇文章里提到了`lib-flexible`和`px2rem`。
   -    3.3 [vh vw配合rem](https://juejin.im/entry/59b00e46f265da2491513bcc)

> 移动端视频自动播放问题
1. 

> 移动端出现[[Intervention] Unable to preventDefault inside passive event listener due to target being treated as passive. See…]
1. [原因](https://developers.google.com/web/updates/2017/01/scrolling-intervention)
2. [解决方案](https://blog.csdn.net/hhlljj0828/article/details/79497734)
如果你用了fastclick这个库，然后出现了类似问题，可以尝试修改源码里的touchstart事件。

> 性能分析
1. [谷歌调试工具](https://developers.google.com/web/tools/chrome-devtools/)
   -   1.1 [网络性能优化](https://developers.google.com/web/tools/chrome-devtools/network-performance/)
    包括issue在内，有一些场景和优化方法，总结起来就是利用好 时间瀑布，看到底在哪一步慢了，然后排除法。

> 前端各种距离

> hybrid
1. [原理](https://www.jianshu.com/p/f3d9382eae78)
2. [为什么打开中间页可以唤起app](https://www.cnblogs.com/chaoyuehedy/p/8919656.html)
3. [连续5篇hybrid介绍](https://www.cnblogs.com/dailc/p/5931324.html)

> 监控
1. [监控日志发现script error `crossorigin`](https://www.chrisyue.com/what-the-hell-is-crossorigin-attribute-in-html-script-tag.html)
2. [关于1.的引申](https://stackoverflow.com/questions/18336789/purpose-of-the-crossorigin-attribute/18336863#18336863)

> 打包工具
   

> 加密技术

> css  
1. box-shadow()
> html  

> js

> 埋点技术
1. [使用 navigator.sendBeacon() 上报数据 ](http://kaifage.com/notes/76/navigator-sendBeacon.html)

> seo

> 缓存方案
1. [Last-Modify、ETag、Expires和Cache-Control(转载)](https://www.cnblogs.com/coolmanlee/archive/2012/12/06/2805030.html)

> 模块加载技术 主要是CJS、ESM
1. [CJS、ESM的相互引用](https://medium.com/@giltayar/native-es-modules-in-nodejs-status-and-future-directions-part-i-ee5ea3001f71
)
2. How do CommonJS modules work？
   -    2.1[原理讲解](http://fredkschott.com/post/2014/06/require-and-the-module-system/)
   -    2.2[源代码](https://github.com/nodejs/node/blob/master/lib/internal/modules/cjs/loader.js)
   -    2.3[帮组源码理解](http://www.infoq.com/cn/articles/nodejs-module-mechanism)
   -    2.4[帮组源码理解](http://f2e.souche.com/blog/a-js-problem-about-global/)
   

> AST

> nodejs
1. module.js:
    1.1 看2.1、2.2、2.3

> git 
1. 

> canvas和可视化学习
1. [图片到canvas上模糊的解决思路](https://www.html5rocks.com/en/tutorials/canvas/hidpi/)
2. [毛刺](https://www.cnblogs.com/joyho/articles/3557223.html)

> 今日学习计划：

> 如果有想了解的方面，但是我上面没有提及的，请在issue上留言，我会补充上去。