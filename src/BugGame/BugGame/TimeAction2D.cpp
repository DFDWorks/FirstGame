////////////////////////////////////////
// TimeAction2D.cpp 
//
// Authors: Fomin Eugene
//
// Description:
////////////////////////////////////////


////////////////////////////////////
// Include
#include "TimeAction2D.h"
   
	////////////////////////////////////
	// Class TimeAction2D
	//
	////////////////////////////////////
	TimeAction2D::TimeAction2D()
		: m_timer( 0.0f )
		, m_time( 0.0f )
		, m_cycled( false )
	{
		
	}

	////////////////////////////////////
	TimeAction2D::~TimeAction2D()
	{

	}

	////////////////////////////////////
	bool TimeAction2D::init()
	{

		return true;
	}

	////////////////////////////////////
	bool TimeAction2D::init( const TimeAction2DPtr& obj )
	{
		if( !Action2D::init( obj ) )
			return false;

		m_timer = obj->m_timer;

		return true;
	}

	////////////////////////////////////
	void TimeAction2D::update( F32 dt )
	{
		Action2D::update( dt );

		if( ActionStatus::InProgress == getStatus() )
		{
			m_timer += dt;

			if( m_timer >= getTime() )
			{
				if( !getCycled() )
					m_timer = getTime();
				else
					m_timer -= getTime();
			}

            if( getTime() > 0.0f )
                setProgress( m_timer / getTime() );
            else
                setProgress( 1.0f );
			
			if( !getCycled() && m_timer >= getTime() )
				setStatus( ActionStatus::Finished );
		}
	}

	////////////////////////////////////
	void TimeAction2D::stop()
	{
		Action2D::stop();
		m_timer = 0.0;
		setProgress( 0.0f );
	}

	////////////////////////////////////
	void TimeAction2D::finish()
	{
		Action2D::finish();
		m_timer = getTime();
		setProgress( 1.0f );
	}

	////////////////////////////////////
	void TimeAction2D::setProgress( F32 progress )
	{
		Action2D::setProgress( progress );
	}
