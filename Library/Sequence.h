#pragma once


template<class T>
class Sequence {
private:
	typedef void(T::*Logic)();
	Logic _Sequence;
	int Frame;
protected:
	Sequence() {}
	inline void Sequence::RunSequence() {
		Frame++;
		T* p = static_cast<T*>(this);
		(p->*_Sequence)();
	}
	
public:
	virtual ~Sequence() {}

	//getter
	inline int GetFrame() { return Frame; }
	inline Logic GetSequence() { return _Sequence; }

	//setter
	inline void SetFrame(int _Frame) { Frame = _Frame; }
	inline void setSequence(Logic _Seq) {
		Frame = -1;
		_Sequence = _Seq;
	}
};
