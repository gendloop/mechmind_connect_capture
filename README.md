# test_mechmind_connect

connect & capture & disconnect

* pcl [下载链接](https://www.aliyundrive.com/s/YWF1TPe846F)

* mecheye sdk [下载链接](https://www.aliyundrive.com/s/fgCW2Bcsf9e) 

* sdk使用 
  ```md
  http://docs.mech-mind.net
  账号  mechmind431
  密码  RUA9babUDC4E
  ```

* 环境配置

  在项目源目录，即`env.bat`所在目录下
  使用 `shift`+右击 点击 <u>在此处打开powershell窗口</u> 

  运行

  ```shell
  # 若不一致，请替换 "pcl 1.9.1", "mecheyesdk 1.6.0" 路径
  $pcl_root="D:\LibInstall\pcl\1.9.1"
  $mecheyesdk_root="D:\LibInstall\mecheyesdk\1.6.0"
  start-process -filepath "env.bat" -argumentlist $pcl_root,$mecheyesdk_root
  ```

