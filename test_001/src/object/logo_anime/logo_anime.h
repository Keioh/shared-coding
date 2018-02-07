#pragma once
#include "header\object.h"


class Logo_anime
{
public:
	float time;//数値を減らす時間を指定する変数
	float alpha_blend_speed;//α値を保存する変数。

	float anime_x, speed_x;//x方向へのアニメーション数値の保存,1フレームの移動量

	//画像データもろもろ
	Object logo_D;
	Object logo_d;
	Object logo_i, logo_i_2;
	Object logo_l;
	Object logo_o;
	Object logo_p;

	void setup(float pos_x, float pos_y, float alpha_speed = 255);
	void update(float next_time_count = 0);
	void draw(bool wire = false);
};