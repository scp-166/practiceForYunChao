# web前端
- 安装webstorm和phpstudy
**注意**phpstudy需要用管理员身份运行

- 语法
    - 在`style`中可以使用css和js的超链接
    ` <link rel="stylesheet" href="css.css"> 外部链接css`
    `    <script type="text/javascript" src="jquery-3.3.1.js"></script>`
    或者使用内嵌
    `#x{}`：id为x的属性
    `x.y{}`: x部件可用的y类的属性，x可为空
    
    
## 读取json文件并且显示在页面上，可水平滚动
- .html
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <title>Title</title>

            <script type="text/javascript" src="jquery-3.3.1.js"></script> 载入jquery文件
            <script src="js.js"></script> 自定义js
            <style>
                .Outer {
                    position: absolute; 绝对路径
                    top: 200px;
                    width: 1000px;
                    left: 200px;
                    overflow: auto; 显示滚动条
                }
                .Sublayer {

                    white-space: nowrap; 该层次及以下部件显示水平
                }
                .Inter {
                    width: 30px;
                    border: 1px solid #999;

                    display: inline-block; 按块排列
                    text-align: center; 文本水平
                    white-space: normal; 该层次及以下部件显示正常
                }
            </style>
        </head>
        <body>
        <div class="Outer">
            <div class="Sublayer">
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
                <div class="Inter"></div>
            </div>
        </div>
        <input type="button" value="Ajax提交" onclick="Ajax();" /> 设置一个按钮，点击执行Ajax()函数

        </body>
        </html>
- .js
        var Ajax = function ()
        {
            var divArr = document.getElementsByClassName('Inter'); 获得所有类名为Inter的div
            for (var i=0; i<divArr.length; i++)
                divArr[i].innerHTML=""; 值置空
            var textNode;
            $.getJSON ("./userinfo.txt", function (data) 获得json数据
            {
                var jsonLength = data.length; 内容个数

                for (var i = 0; i < jsonLength; i++) {
                    textNode = document.createTextNode(data[i].name);
                    divArr[i].append(textNode); 逐一加入
                }
            });
        }

- 运行
点击前
![before](./picture/day11/before.PNG)
点击后
![after](./picture/day11/after.PNG)
json数据
![jsondata](./picture/day11/json.PNG)