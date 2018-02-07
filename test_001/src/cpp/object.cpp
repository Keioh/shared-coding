#include "header\object.h"


//����������(x�̏����ʒu,y�̏����ʒu,�摜�ւ̑��΃p�X,���u�����h�̑���,�~�̏ꍇ�͔��a�����)
void Object::setup(float pos_x, float pos_y, char* path, float alpha_speed, float radius)
{
	graphics.load(path);//�摜�ǂݍ���

	position_x = graphics_position_x = pos_x;
	position_y = graphics_position_y = pos_y;
	if (alpha_speed >= 255)//alpha_speed��255�ȏ�Ȃ�alpha��255����
	{ 
		alpha = 255;
	}
	else
	{
		alpha = 0;
	}
	a_speed = alpha_speed;//���l�����Z������ʂ�a_speed�ɑ��

	Impact::setup(position_x, position_y, graphics.getWidth(), graphics.getHeight(), radius);//�����蔻��
}

//�A�j���[�V���������B
void Object::update(float moved_x, float moved_y, float rate)
{
	alpha += a_speed;
	if (alpha >= 255)alpha = 255;
	if (alpha <= 0)alpha = 0;

	position_x = (moved_x * rate) + graphics_position_x;//�摜��x�����Ɉړ�������B
	position_y = (moved_y * rate) + graphics_position_y;//�摜��y�����Ɉړ�������B

	Impact::update(position_x, position_y);//�q�b�g�{�b�N�X���ړ�������B
}

//�`��
void Object::draw(bool wire)
{
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	if (Impact::hit == true)//�q�b�g���Ă���摜���������邭�\������
	{
		if (Impact::click == true) //�q�b�g���N���b�N���Ă����炳��ɖ��邭�\������B
		{ 
			ofSetColor(255, 255, 255, alpha); 
		}
		else
		{
			ofSetColor(235, 235, 235, alpha);
		}
	}
	else
	{
		ofSetColor(200, 200, 200, alpha);//�q�b�g���Ă��Ȃ�������Â��\������B
	}

	graphics.draw(position_x,position_y);//�摜�̕\��
	if (wire == true)Impact::draw();//�����蔻��̃��C���[��\��
}

//ofApp::mouseMoved(int x,int y)�̒��ɋL�q����B�}�E�X�𓮂������Ƃ��Ƀq�b�g����������鏈��
void Object::mouseMovedUpdate(int x, int y)
{
	Impact::mouseMovedUpdate(x, y);//�����蔻��
}

//ofApp::mousePressedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^�����������Ƃ��̏����B
void Object::mousePressedUpdate(int x, int y, int button, int kind_button)
{
	Impact::mousePressedUpdate(x, y, button, kind_button);//�����蔻��
}

//ofApp::mouseReleasedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^���𗣂����Ƃ��̏����B
void Object::mouseReleasedUpdate(int x, int y, int button, int kind_button)
{
	Impact::mouseReleasedUpdate(x, y, button, kind_button);//�����蔻��
}