
#ifndef RAND_GEN_HPP
#define RAND_GEN_HPP

#include <random>
#include <memory>
#include <exception>


class RAND_GEN
{
	using INT_TYPE = int64_t;
	using DIST_TYPE = std::uniform_int_distribution<INT_TYPE>;
	using ENGINE_TYPE = std::mt19937_64;
	using PARAM_TYPE = DIST_TYPE::param_type;
public:

	INT_TYPE get()
	{
		return m_dis(m_gen);
	}

	void set_range(INT_TYPE min, INT_TYPE max)
	{
		m_dis.param(PARAM_TYPE(min, max));
	}

	static std::unique_ptr<RAND_GEN> make(INT_TYPE seed = 1)
	{
		return std::make_unique<RAND_GEN>(seed);
	}

	RAND_GEN(INT_TYPE seed = 1) :
		m_gen(seed)
	{

	}

	RAND_GEN(const RAND_GEN &) = delete;
	RAND_GEN(RAND_GEN &&) = delete;

	RAND_GEN & operator=(const RAND_GEN &) = delete;
	RAND_GEN & operator=(RAND_GEN &&) = delete;

private:

	ENGINE_TYPE m_gen;
	DIST_TYPE m_dis;
};

#endif
