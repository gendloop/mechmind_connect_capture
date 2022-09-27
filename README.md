# test_mechmind_connect

connect & capture & disconnect

* pcl [下载链接](「pcl_1.9.1.exe」https://www.aliyundrive.com/s/YWF1TPe846F 点击链接保存，或者复制本段内容，打开「阿里云盘」APP ，无需下载极速在线查看，视频原画倍速播放。)

* mecheye sdk [下载链接](「mecheyesdk_1.6.0.exe」https://www.aliyundrive.com/s/fgCW2Bcsf9e 点击链接保存，或者复制本段内容，打开「阿里云盘」APP ，无需下载极速在线查看，视频原画倍速播放。) 

* sdk使用 
  ```md
  http://docs.mech-mind.net
  账号  mechmind431
  密码  RUA9babUDC4E
  ```

* 环境配置

  在目录`..\test_mechmind_connect`目录下
  使用 `shift`+右击 点击 <u>在此处打开powershell窗口</u>

  运行

  ```shell
  # 若不一致，请替换 "pcl 1.9.1", "mecheyesdk 1.6.0" 路径
  $pcl_root="D:\LibInstall\pcl\1.9.1"
  $mecheyesdk_root="D:\LibInstall\mecheyesdk\1.6.0"
  start-process -filepath "env.bat" -argumentlist $pcl_root,$mecheyesdk_root
  ```


