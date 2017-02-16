////////////////////////////////////////
// Action2D_sinMovement
//
// Authors: Fomin Eugene
//
// Description:
////////////////////////////////////////


////////////////////////////////////
// Include
#include "Action2D_sinMovement.h"

	////////////////////////////////////
	// Const

    
	////////////////////////////////////
	// Class Action2D_sinMovement
	//
	////////////////////////////////////
	Action2D_sinMovement::Action2D_sinMovement()
		: m_amplitude( 10.0f )
		, m_isXAxis( false )
		, m_lastProgress(0.0f)
	{
		//registerProperty( m_amplitude );
		//registerProperty( m_isXAxis );

		m_cycled = true;
	}

	////////////////////////////////////
	Action2D_sinMovement::~Action2D_sinMovement()
	{

	}

	////////////////////////////////////
	Action2D_sinMovementPtr Action2D_sinMovement::Create( F32 time, F32 amplitude )
	{
		CREATE( Action2D_sinMovement, init( time, amplitude ) );
	}

	////////////////////////////////////
	Action2D_sinMovementPtr Action2D_sinMovement::Create( const Action2D_sinMovementPtr& obj )
	{
		CREATE( Action2D_sinMovement, init( obj ) );
	}

	////////////////////////////////////
	bool Action2D_sinMovement::init( F32 time, F32 amplitude )
	{
		if( !TimeAction2D::init() )
			return false;

		m_time = time;
		m_amplitude = amplitude;

		return true;
	}

	////////////////////////////////////
	bool Action2D_sinMovement::init( const Action2D_sinMovementPtr& obj )
	{
		if( !TimeAction2D::init( obj ) )
			return false;		


		return true;
	}

	////////////////////////////////////
	bool Action2D_sinMovement::play()
	{
		if( !TimeAction2D::play() )
			return false;

		return true;
	}

	////////////////////////////////////
	void Action2D_sinMovement::setProgress( F32 progress )
	{
		if( getTargetPure() )
		{
			
			F32 delta = 0;
			
			while( m_lastProgress >= progress )
				m_lastProgress -= 1.0f;

			delta = (sin( progress * 2 * 3.141592 ) - sin( m_lastProgress * 2 * 3.141592 )) * m_amplitude;
			


			if( m_isXAxis )  
				getTargetPure()->setX( getTargetPure()->getX() + delta );
			else
				getTargetPure()->setY( getTargetPure()->getY() + delta );
		}
		m_lastProgress = progress;
	}

