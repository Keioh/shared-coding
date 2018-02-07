#include "object\logo_anime\logo_anime.h"

void Logo_anime::setup(float pos_x, float pos_y, float alpha_speed)
{
	anime_x = -25;//アニメーション開始位置をずらす。
	speed_x = 0.2f;//アニメーションのスピードを0.2fに設定

	alpha_blend_speed = alpha_speed;//alpha_speedをalpha_blend_speedに代入

	//画像をロード
	logo_D.setup(pos_x, pos_y, "graphics/logo/logo_D.png", alpha_blend_speed);
	logo_i.setup(pos_x + 50, pos_y, "graphics/logo/logo_i.png", alpha_blend_speed);
	logo_p.setup(pos_x + 75, pos_y + 25, "graphics/logo/logo_p.png", alpha_blend_speed);
	logo_l.setup(pos_x + 110, pos_y, "graphics/logo/logo_l.png", alpha_blend_speed);
	logo_o.setup(pos_x + 150, pos_y - 2, "graphics/logo/logo_o.png", alpha_blend_speed);
	logo_i_2.setup(pos_x + 185, pos_y, "graphics/logo/logo_i.png", alpha_blend_speed);
	logo_d.setup(pos_x + 213, pos_y - 4, "graphics/logo/logo_d_small.png", alpha_blend_speed);
}

void Logo_anime::update(float next_time_count)
{
	if (logo_D.alpha >= 255)//logo_Dのα値が255以上になったら
	{
		speed_x = 0;//アニメーションのスピードを0.0fにする
		time++;//時間を増やす。
	}

	if (time > next_time_count)//時間がある一定以上になったら
	{
		speed_x = 0.2f;//アニメーションのスピードを再び0.2fにする。
		//それぞれのα値をalpha_speedの二倍減らす。(なぜ2倍かというと、元の増加量と相殺するためです。)
		logo_D.alpha -= alpha_blend_speed * 2;
		logo_d.alpha -= alpha_blend_speed * 2;
		logo_i.alpha -= alpha_blend_speed * 2;
		logo_i_2.alpha -= alpha_blend_speed * 2;
		logo_l.alpha -= alpha_blend_speed * 2;
		logo_o.alpha -= alpha_blend_speed * 2;
		logo_p.alpha -= alpha_blend_speed * 2;

		if (logo_D.alpha <= 0)
		{
			speed_x = 0.0f;//アニメーションのスピードを0.0fにする
		}
	}



	anime_x += speed_x;//アニメーションのスピードをアニメーション開始位置に足す。
	

	//それぞれ座標をアップデート
	logo_D.update(anime_x);
	logo_d.update(anime_x);
	logo_i.update(anime_x);
	logo_i_2.update(anime_x);
	logo_l.update(anime_x);
	logo_o.update(anime_x);
	logo_p.update(anime_x);
}

void Logo_anime::draw(bool wire)
{
	logo_D.draw(wire);
	logo_d.draw(wire);
	logo_i.draw(wire);
	logo_i_2.draw(wire);
	logo_l.draw(wire);
	logo_o.draw(wire);
	logo_p.draw(wire);
}