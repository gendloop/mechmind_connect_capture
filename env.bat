:: %~1 pcl_root
:: %~2 mecheyesdk_root
@echo off
@title env

set pcl_root=%~1
set mecheyesdk_root=%~2

if exist pcl_root ( 
	echo "pcl_root is not exist."
	pause
	goto :eof
)

if exist mecheyesdk_root ( 
	echo "mecheyesdk_root is not exist."
	pause
	goto :eof
)

call :pcl
call :mecheyesdk
pause
goto :eof

:pcl
copy "%pcl_root%\pcl_1.9.1_debug_x64.props"
echo "%pcl_root%\pcl_1.9.1_debug_x64.props"
copy "%pcl_root%\pcl_1.9.1_release_x64.props"
echo "%pcl_root%\pcl_1.9.1_release_x64.props"
exit /b

:mecheyesdk
copy "%mecheyesdk_root%\mecheyesdk_1.6.0_debug_x64.props"
echo "%mecheyesdk_root%\mecheyesdk_1.6.0_debug_x64.props"
copy "%mecheyesdk_root%\mecheyesdk_1.6.0_release_x64.props"
echo "%mecheyesdk_root%\mecheyesdk_1.6.0_release_x64.props"
exit /b

:eof
