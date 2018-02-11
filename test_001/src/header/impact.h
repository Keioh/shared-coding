//当たり判定の基本クラス

#pragma once
#include <math.h>
#include "header\define.h"
#include "ofMain.h"


class Impact : public ofBaseApp
{

public:
	bool hit, click;//ヒット確認変数と、クリック確認変数
	float position_x, position_y;//マウスポジション
	float width, height;//大きさ
	float radius_buffer;//半径

	void setup(float pos_x, float pos_y, float size_x = 0, float size_y = 0, float radius = -1);//当たり判定の初期化(pos_x,posyは判定開始位置、size_x,size_yは判定の大きさ,radiusが-1の時は判定をBOXに0以上の時はCIRCLE判定になります。
	void update(float moved_x, float moved_y);//Impactが動くときの処理
	void draw(int thick = 2);//判定される範囲をワイヤーで描写します。ヒットしたら赤、ヒットなしで青。(線の太さは初期で2)

	void mouseMovedUpdate(int x, int y);//ofApp::mouseMoved(int x,int y)の中に記述する。マウスを動かしたときにヒット判定をさせる処理。
	void mousePressedUpdate(int x, int y, int button, int kind_button);//ofApp::mousePressedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを押したときの処理。
	void mouseReleasedUpdate(int x, int y, int button, int kind_button);//ofApp::mouseReleasedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを離したときの処理。

};
