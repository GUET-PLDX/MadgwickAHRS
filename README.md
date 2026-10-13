# MadgwickAHRS

提供姿态和航向参考系统（AHRS）功能的模块 / A module providing Attitude and Heading Reference System (AHRS) functionality

## 硬件需求 / Required Hardware

ramfs

## 构造参数 / Constructor Arguments

* beta:                  0.05
* gyro\_topic\_name:       "imu\_gyro"
* accl\_topic\_name:       "imu\_accl"
* quaternion\_topic\_name: "ahrs\_quaternion"
* euler\_topic\_name:      "ahrs\_euler"
* task\_stack\_depth:      2048

## 依赖 / Depends

无（No dependencies）

## 时间戳约定

AHRS 以 gyro topic 作为主时间线。每次姿态更新使用 gyro 消息的 Topic envelope timestamp 计算 `dt`，并用同一个 timestamp 发布 `ahrs_quaternion` 与 `ahrs_euler`。

## LibXR 2.0 静态装配

使用 xrobot 1.0.1 的 `module` / 有序 `args`；构造函数显式注入外设与服务，实例按依赖顺序创建。参数名和顺序以头文件中的构造函数为准，固件示例见 `User/RobotConfig/`。

保留 PLDX 控制、协议、超时与离线保护。 `OnMonitor()` 由生成的监控循环直接调用。
