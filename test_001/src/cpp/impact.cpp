#include "header\impact.h"

//�����蔻��̏�����(pos_x,posy�͔���J�n�ʒu�Asize_x,size_y�͔���̑傫��,radius��-1�̎��͔����BOX��0�ȏ�̎���CIRCLE����ɂȂ�܂��B
void Impact::setup(float pos_x, float pos_y, float size_x, float size_y, float radius)
{
	//�|�W�V�����Ƒ傫���Ɣ��a�����ꂼ����
	position_x = pos_x;
	position_y = pos_y;
	width	= size_x;
	height	= size_y;
	radius_buffer = radius;
}

//Impact�������Ƃ��̏���
void Impact::update(float moved_x, float moved_y)
{
	position_x = moved_x;//position_x�ɓ������ʂ𑫂��B
	position_y = moved_y;//position_y�ɓ������ʂ𑫂��B
}

//���肳���͈͂����C���[�ŕ`�ʂ��܂��B(�q�b�g������ԁA�q�b�g�Ȃ��Ő�)
void Impact::draw(int thick)
{	
	if(hit == true)//�F�̕ύX
	{
		if (click == true)//�N���b�N����Ă�����
		{
			ofSetColor(0, 255, 0);//�N���b�N����Ă�����̐F��΂ɕύX
		}
		else
		{
			ofSetColor(255, 0, 0);//�q�b�g���Ă�������̐F��ԂɕύX
		}
	}
	else
	{
		ofSetColor(0, 0, 255);//�q�b�g���Ă�������̐F��ɕύX
	}

	ofSetLineWidth(thick);//���̑�����ύX
	ofSetCircleResolution(128);//�~�̉𑜓x��ύX
	if (radius_buffer <= -1)//���a�w�肪-1�̎�
	{
		ofDrawLine(position_x, position_y, position_x + width, position_y);//��̉���
		ofDrawLine(position_x, position_y, position_x, position_y + height);//���̏c��
		ofDrawLine(position_x + width, position_y, position_x + width, position_y + height);//�E�̏c��
		ofDrawLine(position_x, position_y + height, position_x + width, position_y + height);//���̉���
	}
	else if (radius_buffer >= 0)//���a�w�肪0����̎�
	{
		ofNoFill();
		ofDrawCircle(position_x, position_y, radius_buffer);
	}
}

//ofApp::mouseMoved(int x,int y)�̒��ɋL�q����B�}�E�X�𓮂������Ƃ��Ƀq�b�g����������鏈���B
void Impact::mouseMovedUpdate(int x, int y)
{
	if (radius_buffer >= 0)//���a��0�ȏ�Ȃ�
	{
		if (std::pow((x - position_x), 2) + std::pow((y - position_y), 2) <= std::pow(radius_buffer, 2))//�~�ƃ}�E�X�̌��݈ʒu�Ƃ̓����蔻��
		{
			hit = true;//�������Ă�����true
		}
		else
		{
			hit = false;//�������Ă��Ȃ�������false
		}
	}
	else if (radius_buffer <= -1)//���a��-1�ȉ��Ȃ�
	{
		if ((position_x <= x) && (position_x + width >= x) && (position_y <= y) && (position_y + height >= y))//�l�p�^�C�v�̃}�E�X�̓����蔻��
		{
			hit = true;//�������Ă�����true
		}
		else
		{
			hit = false;//�������Ă��Ȃ�������false
		}
	}

}

//ofApp::mousePressedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^�����������Ƃ��̏����B
void Impact::mousePressedUpdate(int x, int y, int button, int kind_button)
{
	if (hit == true)
	{
		if (button == kind_button && true)//button��kind_button�Ɠ����Ȃ�
		{
			click = true;//�N���b�N��true
		}
	}
}

//ofApp::mouseReleasedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^���𗣂����Ƃ��̏����B
void Impact::mouseReleasedUpdate(int x, int y, int button, int kind_button)
{
	if (hit == true)
	{
		if (button == kind_button && true)//button��kind_button�Ɠ����Ȃ�
		{
			click = false;//�N���b�N��false
		}
	}
}