# 字幕下载与滚动播放

## 字幕滚动效果
- 首尾相连效果
	- `int stepWidth`来控制速率
	- `drawText()`函数用偏移宽度(stepWdith和offset)控制当前文本位置
	- 第一个`drawText()`控制文本接触左边融入。本过程称为步骤1
	- 第二个`drawText()`控制文本右边出现，接触左边消失。本过程称为步骤2
	- 在步骤1达到文本融入左边后，且步骤2即将结束(文本要接近左边)，此时步骤1和步骤2全部结束，重新回到步骤1的文本接触左边，步骤2的文本出现于右边的状态
```java
 int clong = width() - stepWidth * offset;
    painter.drawText(0-stepWidth *offset,0,width(),height(),Qt::AlignLeft | Qt::AlignVCenter,text());
    painter.drawText(clong,0,width(),height(),Qt::AlignLeft | Qt::AlignVCenter,text().left(offset));
```
	- 修改宽度比较
```java
    void rolltext::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == myTimerId)
    {
        ++offset;
        if(offset*stepWidth  >= width())	//偏移宽度比较
            offset = 0;
        scroll(-1,0);//把窗口部件的内容向左滚动一个像素
    }else
    {
        QWidget ::timerEvent(event);
    }
}
```

## 字幕文本下载与解析
- 下载类似视频下载
- 解析类似视频下载列表解析
```java
QString FileTransaction::get_roll_text()
{
    QString rolltext;
    QFile file("/media/video/rolltext");
    if(!file.exists())return "update..";

    file.open(QIODevice::ReadOnly);

    rolltext = file.readAll();
    rolltext.remove("\n");

    file.close();
    return rolltext;
}
```
**"问题"**
第一次没有执行上的问题，非常的激动

## 播放器模块和字幕模块整合
- 也是使用`setParent()`方式固定在一个蓝本ui中，届时作为一个模块使用。
- 运行
![run](./picture/day9/run.PNG)