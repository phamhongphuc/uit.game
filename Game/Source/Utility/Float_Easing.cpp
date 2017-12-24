﻿#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>
const float maxTime = 1.f;

Float_Easing::Float_Easing() {
	mEase = Ease::stop;
	mType = Type::none;
	mNow = 0;
}
Float_Easing::Float_Easing(float pStart, Type pType, float pVelocity) {
	mEase = Ease::stop;
	mType = pType;
	SetVelocity(pVelocity);
	operator<<(pStart);
}
void Float_Easing::operator<<(float pValue) {
	mNow = mLast = pValue;
}
void Float_Easing::operator=(float pLast) {
	mLast = pLast;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mLast + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mLast - pDelta;
}
bool Float_Easing::SetVelocity(float value) {
	mVelocity = value;
	return true;
}
float Float_Easing::operator()() {
	return float(mNow);
}

void Float_Easing::Update(float dt = 0) {
	switch (mType) {
	case Type::gravity:		//# Gravity
		switch (mEase) {
		case in:
			mNow += mVelocity * dt;
			mVelocity += dt * 1000;

			if (mNow >= mLast) {
				mEase = Ease::stop;
				mNow = mLast;
				mVelocity = 0;
			}
			break;
		case stop:
			if (mVelocity != 0 || mLast != mNow) {
				if (mVelocity == 0 && mNow >= mLast) mNow = mLast;
				else mEase = Ease::in;
			}
			break;
		}
		break;
	case Type::none:		//# None
		mNow = mLast;
		break;
	case Type::linear:
		switch (mEase) {
		case in:
			mNow += (mNow < mLast ? 1 : -1) * min(abs(mVelocity)*dt, abs(mNow - mLast));
			if (mNow == mLast) mEase = stop;
			break;
		case stop:
			if (mLast != mNow) {
				mEase = Ease::in;
			}
			break;
		}
		break;
	case Type::pull:
		const float velo = 100.f;
		switch (mEase) {
		case in:
			// auto l = abs(mLast - mNow);
			// auto mmm = sqrt(mVelocity - l*l);
			mTime += dt;
			mNow += (mLast - mNow) / (maxTime - mTime) * dt;

			if (mNow == mLast) mEase = stop;
			break;
		case stop:
			if (mLast != mNow) {
				mTime = 0;
				mEase = Ease::in;
			}
			break;
		}
		break;
	}
}