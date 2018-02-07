//オブジェクトを作る際の基本となるクラス

#pragma once
#include "header\define.h"
#include "header\impact.h"


class Object : public Impact
{
public:
	ofImage graphics;//画像を扱うための変数を宣言
	float position_x, position_y;//ポジション
	float graphics_position_x, graphics_position_y;//画像ポジション
	float alpha, a_speed;//αブレンド用変数とα値加算の速さ変数

	void setup(float pos_x, float pos_y, char* path, float alpha_speed = 255, float radius = -1);//初期化処理(xの初期位置,yの初期位置,画像への相対パス,αブレンドの速さ,円の場合は半径を入力)
	void update(float moved_x = 0.0f, float moved_y = 0.0f, float rate = 1.0f);//アニメーション処理。(1フレームの移動量をmoved_x,moved_yに書くrateは移動倍率1.0fで一倍)
	void draw(bool wire = false);//描写

	void mouseMovedUpdate(int x, int y);//ofApp::mouseMoved(int x,int y)の中に記述する。マウスを動かしたときにヒット判定をさせる処理。
	void mousePressedUpdate(int x, int y, int button, int kind_button);//ofApp::mousePressedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを押したときの処理。
	void mouseReleasedUpdate(int x, int y, int button, int kind_button);//ofApp::mouseReleasedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを離したときの処理。

};