#pragma once

template<typename T>
class RangeIterator sealed
{
public:
	typedef T RangeType;
	typedef RangeIterator<RangeType> SelfType;
	typedef typename RangeType::ValueType ValueType;

private:
	const RangeType* const m_range;
	ValueType m_value;

public:
	RangeIterator(const RangeType* const range, ValueType startValue)
		: m_range(range), m_value(startValue)
	{};

	operator ValueType() const
	{
		return m_value;
	}
	ValueType operator*() const
	{
		return m_value;
	}
	SelfType& operator++()
	{
		m_value += m_range->step();
		return *this;
	}
	SelfType operator++(int)
	{
		SelfType tempIt(*this);
		++(*this);
		return tempIt;
	}
	bool operator!= (const SelfType& right)
	{
		return !(*this == right);
	}
};

template <typename T>
class Range
{
private:
	T m_min, m_max, m_step;

public:
	typedef size_t SizeType;
	typedef T ValueType;
	typedef T RangeType;

	Range(T min, T max, T step = T(1))
		: m_min(min), m_max(max), m_step(step)
	{};

	ValueType operator[](RangeType& i) const
	{
		return (m_min + (i * m_step));
	}
	SizeType size()
	{
		return static_cast<SizeType>((m_max - m_min) / m_step);
	}
	ValueType step() const
	{
		return m_step;
	}
	RangeIterator<Range<T>> begin()
	{
		return RangeIterator<Range<T>>(this, m_min);
	}
	RangeIterator<Range<T>> end()
	{
		return RangeIterator<Range<T>>(this, m_min + size() * m_step);
	}
};