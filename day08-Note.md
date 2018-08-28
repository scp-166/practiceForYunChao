# 多媒体播放和视频下载
- QT如何启动进程
```java
        mProcess = new QProcess();
        ...
        mProcess->start("process", "参数");```
## 练习
**遇到的问题分析如何实现要求相应的逻辑**
**头皮发麻**

- 实现以下要求：
1. 每隔30秒下载视频清单movie.list
2. 解析movie.list,其内容一行一个文件名
3. 查询本地视频，与movie.list中的内容对比，若本地有则跳过，如果没有则下载
4. 循环播放本地视频
- 思路
	- 步骤1、2、3可以作为一个模块，使用QTimer和connect达到30秒定时执行
		- 所以在filetransaction.h中先声明一个槽函数`void CheckAndDownload();`和一个QTimer指针
		- 在filestransaction.cpp中的构造函数添加以下内容
		```java
                timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(CheckAndDownload()));	//溢出则执行
                timer->start(30000); // 每隔30s```
    	- 准备填写`CheckAndDownload()`，先定义所需的变量
       ```java
                FileTransaction tranfile;	//下载视频类
                Common cm;	//辅助类
                QString videoPath = "/media/video";	//指定视频存放地址
                QString movieListPath = "/media/video/movie.list";  //指定清单存放地址
                QStringList suffix;	//后缀名
                suffix << "*.mp4" << "*.wmv" << "*.avi";```
	- 步骤1，先判断movie.list是否存在于指定目录，存在则删除，然后下载新的movie.list
	代码如下：
    ```java
            QFile file(movieListPath);
            if (file.exists())
            {
                file.remove();
            }

           tranfile.set_remote_path("http://47.106.177.249/downup/media/");
           tranfile.get_file("movie.list", movieListPath);
           cm.Delay(2000);```

	其中getFileNames是用于读取指定目录内所有指定后缀名的函数
	```java
                //该功能函数保存在一个辅助类Common中
                QStringList Common::getFileNames(const QString &path, const QStringList suffix)
            {
                QDir dir(path);
                QStringList nameFilters;
                nameFilters << suffix;
                QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
                return files;
            }```
	- 步骤2，使用QFIle和QTextStream获得movie.list的数据，存储在一个QStringList中
	```java
				//该功能函数保存在一个辅助类Common中
                QStringList Common::readFile(QString path)
            {
                QStringList fileNameInFile;
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    return fileNameInFile;
                }
                QTextStream in(&file);

                while (!in.atEnd()) //循环到底
                {
                QString line = in.readLine();	//读取一行
                fileNameInFile << line ;	//保存一行
                }
                file.close();
                return fileNameInFile;
            }```
	调用方式：
	`QStringList xxx = cm.readFile(movieListPath);`
	- 步骤3，使用两个for循环比较两个QStringList(下载清单与本地视频)的内容，如果相同，则删除下载清单中相应的部分。然后根据下载清单中的内容进行下载
	```java
            QStringList nameInpath =  cm.getFileNames(videoPath, suffix); //获得本地视频列表

            QStringList nameinFile = cm.readFile(movieListPath); // 解析下载清单列表

            int videoNumInFile = nameinFile.size(); //下载清单内容个数

            for (int i=0; i<nameInpath.size();i++)
            {
                for(int j=0; j<videoNumInFile; j++)
                {
                    if (!(nameInpath[i].compare(nameinFile[j]))) // 比较两个清单的内容
                    {
                        nameinFile.removeAt(j);//相同则删除下载清单相应的内容
                        videoNumInFile--;  //减少大小1
                    }
                }
            }

            if (!(nameinFile.isEmpty())) // 如果不为空
            {
            	//根据清单下载本地未有的内容
                for (int i = 0; i<nameinFile.size(); i++)
                {
                    tranfile.set_remote_path("http://47.106.177.249/downup/media/");
                    tranfile.get_file(nameinFile[i], "/media/video/" +nameinFile[i]);
                    cm.Delay(12000);
                }
            }```
		**调用只需要在main函数实例化fileTransaction，即可启动定时器，调用CheckAndDownload()**
	- 步骤4，同理，在视频播放类Videoplayer中也是用QTimer定时检查本地视频目录(check_video())，方便及时播放新下载的文件
		定义一个全局变量`QStringList videolist;`用来存放播放列表
	```java
    		//构造函数中
            timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(check_video())); // 响应check
            timer->start(4000); // 每隔4s
    ```
    
    ```java
            //检查函数
            void VideoPlay::check_video()
            {
                Common cm;

                QStringList suffix ;
                suffix<< "*.mp4" << "*.wmv" << "*.avi";
                QStringList namelist = cm.getFileNames("/media/video", suffix); // 获取本地视频列表
                videolist.clear();  //注意及时清空播放列表

                for (int i=0; i<namelist.size(); i++)
                {
                    videolist << "/media/video/"+namelist[i];
                }

                set_video_path(videolist);  //设置播放列表
            }
    ```
    **问题**
    `videolist.clear();`未加时，videolist不断添加已有的本地视频名称，导致新下载的视频难以播放
    **解决**
    添加`videokist.clear();`即可，本次问题是没有注意到list的特点：可以重复。
    
    函数调用：
    ```java
        //在主函数中调用
        extern QStringList videolist;
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            FileTransaction f; // start timer

            Common cm;
			//以下内容是启动时默认播放已有内容，check_video()需要时间溢出才可执行
            QStringList suffix ;
            suffix<< "*.mp4" << "*.wmv" << "*.avi";
            QStringList namelist = cm.getFileNames("/media/video", suffix); // 获得本地视频列表

            for (int i=0; i<namelist.size(); i++)
            {
                videolist << "/media/video/"+namelist[i];
            }

			//循环播放
            VideoPlay w;
            w.set_mplayer_path("mplayer");
            w.set_video_path(videolist); //设置播放列表
            w.show();

            w.start_video(); //开始播放

            return a.exec();
        }

    ```
- 运行