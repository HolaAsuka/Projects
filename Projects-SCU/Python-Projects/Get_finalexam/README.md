# Get_finalExam
Get final exam results automatically for SCU

由Y4tacker独立编写
作者:Y4stacker
[CSDN博客地址](https://blog.csdn.net/solitudi)：(点击左侧直达)
# 序言

本程序只为了作者学习爬虫模块的小实战，请在本地测试后24h内删除
如果您觉得本项目对你有帮助的话，可以给本项目一个`star`来鼓励一下~

# 免责声明：

本人所发布的一切资源仅限用于学习和研究目的；不得将上述内容用于商业或者非法用途，否则，一切后果请用户自负。您必须在下载后的24个小时之内，从您的电脑中彻底删除上述内容。

附: 二○○二年一月一日《计算机软件保护条例》第十七条规定：为了学习和研究软件内含的设计思想和原理，通过安装、显示、传输或者存储软件等方式使用软件的，可以不经软件著作权人许可，不向其支付报酬！鉴于此，也希望大家按此说明研究软件！

# 更新日志

2020.7.1 上传项目
2020.7.2 修复了一处逻辑错误，该错误导致会连续获取两次所有成绩
2020.7.3 增加了控制台系统提示，优化了用户体验


# 说明
## 如何食用

Step1：打开QQ邮箱打开POP3/SMTP服务，申请口令(如果需要邮件提示功能，否则请注释掉相关源码smtp相关py，在selectcourse文件中查询是否选中模块)，当然可以食用ServerChan服务，很简单不作讲解

Step2：在最上方中填写个人基本信息，其中username，password分别为你的学号与密码，由于基于QQ邮箱，mail_user，mail_pass分别为QQ邮箱账号以及你的口令，注意不是QQ密码

Step5：运行__init__.py

