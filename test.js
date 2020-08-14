/*
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-14 13:42:57
 * @LastEditTime: 2020-08-14 15:27:52
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\test.js
 * @居居 <jxygzzy@163.com>
 */

 // ==UserScript==
// @name         问卷星自动填
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  随机填写问卷数据
// @author       居居<jxygzzy@163.com><QQ:1924451951>
// @match        *://www.wjx.cn/jq/*
// @grant        none
// ==/UserScript==
(function () {
    'use strict';
    var questions = document.getElementsByClassName("div_question");
    for (var i = 0; i < questions.length; i++) {

        var div_i = questions[i];
        // var Ul = div_i.getElementsByTagName("ulradiocheck");
        var lists = div_i.getElementsByTagName("input");
        if (lists == undefined)
            continue;
        var len = lists.length;
        var slect = Math.floor(Math.random() * len);


        if (lists[slect].type == "radio") { //单选
            lists[slect].checked = true;
        }

        if (lists[slect].type == "checkbox") {//多选
            for (var j = 0; j <= slect; j++) {
                lists[j].checked = true;
            }
        }




    }

    // Your code here...
})();