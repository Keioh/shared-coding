#include "header\impact.h"

//当たり判定の初期化(pos_x,posyは判定開始位置、size_x,size_yは判定の大きさ,radiusが-1の時は判定をBOXに0以上の時はCIRCLE判定になります。
void Impact::setup(float pos_x, float pos_y, float size_x, float size_y, float radius)
{
	//ポジションと大きさと半径をそれぞれ代入
	position_x = pos_x;
	position_y = pos_y;
	width	= size_x;
	height	= size_y;
	radius_buffer = radius;
}

//Impactが動くときの処理
void Impact::update(float moved_x, float moved_y)
{
	position_x = moved_x;//position_xに動いた量を足す。
	position_y = moved_y;//position_yに動いた量を足す。
}

//判定される範囲をワイヤーで描写します。(ヒットしたら赤、ヒットなしで青)
void Impact::draw(int thick)
{
	if(hit == true)//色の変更
	{
		if (click == true)//クリックされていたら
		{
			ofSetColor(0, 255, 0);//クリックされてたら線の色を緑に変更
		}
		else
		{
			ofSetColor(255, 0, 0);//ヒットしていたら線の色を赤に変更
		}
	}
	else
	{
		ofSetColor(0, 0, 255);//ヒットしていたら線の色を青に変更
	}

	ofSetLineWidth(thick);//線の太さを変更
	ofSetCircleResolution(128);//円の解像度を変更
	if (radius_buffer <= -1)//半径指定が-1の時
	{
		ofDrawLine(position_x, position_y, position_x + width, position_y);//上の横線
		ofDrawLine(position_x, position_y, position_x, position_y + height);//左の縦線
		ofDrawLine(position_x + width, position_y, position_x + width, position_y + height);//右の縦線
		ofDrawLine(position_x, position_y + height, position_x + width, position_y + height);//下の横線
	}
	else if (radius_buffer >= 0)//半径指定が0より上の時
	{
		ofNoFill();
		ofDrawCircle(position_x, position_y, radius_buffer);
	}
}

//ofApp::mouseMoved(int x,int y)の中に記述する。マウスを動かしたときにヒット判定をさせる処理。
void Impact::mouseMovedUpdate(int x, int y)
{
	if (radius_buffer >= 0)//半径が0以上なら
	{
		if (std::pow((x - position_x), 2) + std::pow((y - position_y), 2) <= std::pow(radius_buffer, 2))//円とマウスの現在位置との当たり判定
		{
			hit = true;//当たっていたらtrue
		}
		else
		{
			hit = false;//当たっていなかったらfalse
		}
	}
	else if (radius_buffer <= -1)//半径が-1以下なら
	{
		if ((position_x <= x) && (position_x + width >= x) && (position_y <= y) && (position_y + height >= y))//四角タイプのマウスの当たり判定
		{
			hit = true;//当たっていたらtrue
		}
		else
		{
			hit = false;//当たっていなかったらfalse
		}
	}
}

//ofApp::mousePressedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを押したときの処理。
void Impact::mousePressedUpdate(int x, int y, int button, int kind_button)
{
	if (hit == true)
	{
		if (button == kind_button && true)//buttonがkind_buttonと同じなら
		{
			click = true;//クリックをtrue
		}
	}
}

//ofApp::mouseReleasedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを離したときの処理。
void Impact::mouseReleasedUpdate(int x, int y, int button, int kind_button)
{
	if (hit == true)
	{
		if (button == kind_button && true)//buttonがkind_buttonと同じなら
		{
			click = false;//クリックをfalse
		}
	}
}
