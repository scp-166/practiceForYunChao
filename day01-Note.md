##练习
### 五笔
- 打开终端，输入命令（以下为root权限命令）

        apt-get ibus ibus-table lbus-table-wubi

- 右上角`system-setting`->`text entry`
- 左下角`+`号添加`chinese wubi`

### mplayer的源码安装
- 总体步骤：
**Yasm->mplayer->skin+声卡**

- yasm安装
    - 依次执行以下命令
            tar zxvf yasm-1.2.0.tar.gz
            cd yasm-1.2.0/
            cat INSTALL
            ./configure --prefix=/usr/local/yasm
            make
            make install
在`/etc/profile` 文件末尾添加`export PATH="$PATH:/usr/local/yasm/bin"`将yasm加入全局环境变量
`. /etc/profile` 生效环境变量(**注意. 和 /之间有空格**)

- mplayer安装
	- 需要解码器：linux下的解码器all-20100303.tar.bz2，然后执行以下步骤
            sudo mkdir /usr/lib/codecs/
            sudo cp all-20110131/* /usr/lib/codecs/
	- 官网下载源码包**MPlayer-1.3.0.tar.xz** [mplayer download](http://www.mplayerhq.hu/)
	- mplayer的默认安装文件夹在 /usr/local/lib/codecs/ ，将压缩包拷入/usr/local/lib/codecs/ ,解压然后编译：
            cp /mnt/hfgs/myShare/MPlayer-1.3.0.tar.xz  /usr/local/lib/codecs/ 
            cd  /usr/local/lib/codecs/ 
            tar xvf /MPlayer-1.3.0.tar.xz 		//解压
            cd Mplayer.1.3.0
            ./configure --enable-gui
                        --enable-xshape  //编译
**这时出现错误**：
`Error: GTK+ version 2 devel packages were not found (required for GUI).`
解决方法：
        	apt-get install libgtk2.0-dev
如果无法安装，解决方法：换软件源
步骤如下：
            cp /etc/apt/sources.list /etc/apt/sources.list.backup //备份
            Vim /etc/apt/sources.list
在初始模式键入`ggdG`清空文本，或者`999dd`清空文本，然后p粘贴复制好的新软件源即可

	- 完毕后在原Mplayer.1.3.0/目录下
        	make&&make install
	- 完成后，使用gmplayer 出现错误`[skin] file ( /usr/local/mplayer//share/mplayer/skins/default/skin ) not readable.
Skin not found (default).`

		- 从官网底部下载皮肤(比如Blue)，将压缩包拷入皮肤文件夹。

                cd /usr/local/share/mplayer/ skins/
                cp  /mnt/hgfs/myShare/Blue-1.13.tar.bz2  skins/

                //解压skin，重命名为default
                tar xf Blue-1.13.tar.bz2
                cd skins
                mv Blue default
- 终端内输入gmplayer即可调用程序

### 故障
- mplayer没有声音，是因为linux2.4以后的内核逐渐抛弃oss音频架构而转向alsa，而ubuntu缺少alsa的库，所以我们加上就可以了，文件为
`alsa-lib-1.0.27.2.tar.bz2`

- 编译安装alsa-lib
            cd alsa-lib-1.0.27.2/
            ./configure
            make&&make install

- 加载声卡驱动
		modprobe snd_pcm_oss

- 运行 `gmplayer xxx(文件名)`即可
