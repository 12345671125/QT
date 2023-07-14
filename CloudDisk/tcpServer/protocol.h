/*protocol类为协议类，规定cs端之间的通信细节，用于cs端传输数据*/

#ifndef PROTOCOL_H
#define PROTOCOL_H
#pragma once
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <QString>
typedef unsigned int uint;

#define REGIST_OK "regist ok"
#define REGIST_FAILED "regist failed : name existed"

#define LOGIN_OK "login ok"
#define LOGIN_FAILED "login failed : name or pwd error or relogin"

enum ENUM_MSG_TYPE{
    ENUM_MSG_TYPE_MIN = 0,
    ENUM_MSG_TYPE_REGIST_REQUEST, //注册请求
    ENUM_MSG_TYPE_REGIST_RESPOND, //注册回复

    ENUM_MSG_TYPE_LOGIN_REQUEST, //登录请求
    ENUM_MSG_TYPE_LOGIN_RESPOND, //登录回复

    ENUM_MSG_TYPE_ALL_ONLINE_REQUEST, //在线用户请求
    ENUM_MSG_TYPE_ALL_ONLINE_RESPOND,  //在线用户回复

    ENUM_MSG_TYPE_SEARCHUSER_REQUEST, //搜索用户请求
    ENUM_MSG_TYPE_SEARCHUSER_RESPOND, //搜索用户协议

    ENUM_MSG_TYPE_ADDFRIEND_REQUEST, //添加好友请求
    ENUM_MSG_TYPE_ADDFRIEND_RESPOND,//添加好友回复

    ENUM_MSG_TYPE_ADDFRIEND_AGREE, //同意添加好友
    ENUM_MSG_TYPE_ADDFRIEND_REFUSE,//拒绝添加好友

    ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST,//刷新好友请求
    ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND,//刷新好友回复

    ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST, //删除好友请求
    ENUM_MSG_TYPE_DELETE_FRIEND_RESPOND, //删除好友回复

    ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST, //私聊请求
    ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND, //私聊回复

    ENUM_MSG_TYPE_FONLINE_STATUS_REQUEST, //查询好友是否在线请求
    ENUM_MSG_TYPE_FONLINE_STATUS_RESPOND, //查询好友是否在线回复

    //    ENUM_MSG_TYPE,
    //    ENUM_MSG_TYPE,
    ENUM_MSG_TYPE_MAX = 0x00ffffff,
};
struct PDU
{
    uint uiPDULen; //总的协议数据单元大小
    uint uiMsgType; //消息类型
    char caData[128]; //文件名
    uint uiMsgLen; //实际消息长度
    int caMsg[]; //实际消息  直接申请一个指针应该是一个效果？
    static PDU default_respond(uint Type,QString respondStr,uint MsgSize= 0);
    static PDU default_request(uint Type,QString requestStr,uint MsgSize = 0);
};
PDU* createPDU(uint uiMsgLen);
#endif // PROTOCOL_H
