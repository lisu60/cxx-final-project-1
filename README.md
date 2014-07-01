#课表查询管理程序

此项目为本学期C++课程期末加分项目。课表采用[Json](http://json.org/)格式保存，项目中使用了[JsonBox](https://github.com/anhero/JsonBox)库来读取和写入Json文件。

本程序可以查询、添加和删除课程，并以Json格式保存为文件。

项目中对Linux平台和Windows平台分别做了适配，可以直接在不同平台中编译运行。

为了描述方便，以下将该项目的根目录写作*proj-root* （这个目录的名字可能是*cxx-final-project-1* ） 。

下文命令行代码中>符号表示Windows命令行提示符，%表示Linux命令行提示符。

##如何构建(build)本项目

###Windows平台


####前期准备：

* Visual Studio 2010

####步骤：

使用VS2010打开

```bash
 proj-root\windows-build\windows-build.sln 
```

解决方案文件，在VS2010的界面中，右键**解决方案管理器**中的**解决方案'windows-build'**->点击生成解决方案。

###Linux平台

本项目目前仅在Ubuntu 14.04中进行过测试，不能保证在其他发行版中也能正常工作。


####前期准备：

* GCC编译器
* make工具

####步骤：

*1* 在终端中cd至JsonBox目录
```bash
% cd proj-root/JsonBox/
```

*2*  构建JsonBox库
```bash
% make
```

*3* cd至linux-build目录
```bash
% cd proj-root/linux-build/
```

*4* 构建项目
```bash
% make
```


##如何运行本项目

###Windows平台

由于本程序需要接收一个命令行参数（存放课表的Json文件的文件路径），所以直接在VS2010中用默认配置调试是不能成功运行的。



虽然在VS2010环境中可以设置调试时的命令行参数，这里只介绍怎样直接从命令行中运行。

p.s.:
```bash
proj-root\assets\timetable.json
```
是一个供测试使用的课表文件，下文中将用这个文件作为实例中使用的课表文件。

-----------
####步骤：
*1* 按下win-R组合键（windows键加R键），调出“运行”对话框。在输入框中输入

```bash
cmd
```
点击“确定”按钮。

*2* cd至Debug 目录
```bash
> cd proj-root\windows-build\Debug\
```
例如：
```bash
> cd C:\Users\foo-bar\Documents\cxx-final-project-1\windows-build\Debug\
```
*3* 运行windows-build.exe
```bash
> windows-build.exe ..\..\assets\timetable.json
```
用户也可以使用其他的.json文件。

###Linux平台

下文中将使用
```bash
proj-root/assets/timetable.json
```
这个文件作为实例中使用的课表文件。

####步骤：

*1* 在终端中，cd至bin目录
```bash
% cd proj-root/linux-build/bin
```
*2* 运行timetable
```bash
% ./timetable ../../assets/timetable.json
```
用户也可以使用其他的.json文件。