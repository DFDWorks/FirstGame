////////////////////////////////////////
// Action2D.cpp 
//
// Authors: Fomin Eugene
//
// Description:
////////////////////////////////////////


////////////////////////////////////
// Include
#include "Action2D.h"


	////////////////////////////////////
	// Class Action2D
	//
	////////////////////////////////////
	Action2D::Action2D()
		: m_tag( 0 )
		, m_targetPure( NULL )
        , m_status( ActionStatus::None )
        , m_autoDestroy( true )
	{
	}

	////////////////////////////////////
	Action2D::~Action2D()
	{

	}

	////////////////////////////////////
	bool Action2D::init()
	{

		return true;
	}

	////////////////////////////////////
	bool Action2D::init( const Action2DPtr& obj )
	{
		m_target.reset();
		m_targetPure = NULL;
		m_status = obj->m_status;
		m_autoDestroy = obj->m_autoDestroy;
		
		if( m_status == ActionStatus::Cached )
			m_status = ActionStatus::InProgress;

		return true;
	}

	////////////////////////////////////
	void Action2D::update( F32 dt )
	{
		
	}

	////////////////////////////////////
	bool Action2D::play()
	{
		if(		ActionStatus::None != m_status
			&&  ActionStatus::Paused != m_status )
			return false;

		if( !m_target.lock() )
			return false;

		setStatus( ActionStatus::InProgress );
		return true;
	}

	////////////////////////////////////
	void Action2D::pause()
	{
		setStatus( ActionStatus::Paused );
	}

	////////////////////////////////////
	void Action2D::stop()
	{
		setStatus( ActionStatus::None );
	}

	////////////////////////////////////
	void Action2D::finish()
	{
		setStatus( ActionStatus::Finished );
	}

	////////////////////////////////////
	void Action2D::reset()
	{
		stop();
		play();
	}

	////////////////////////////////////
	void Action2D::setStatus( ActionStatus::Enum status )
	{ 
		if( m_status == status )
			return;

		m_status = status; 

		switch( m_status )
		{
			case ActionStatus::Finished:
			{
				if( m_autoDestroy )
					setStatus( ActionStatus::Destroy );

				break;
			}
                
            default:
                break;
		}

	}

	////////////////////////////////////
	void Action2D::setTarget( const GameObjectPtr& target )
	{
		m_target = target;
		m_targetPure = target ? target.get() : NULL;

		if( target )
		{
			reset();
		}
		
	}

	////////////////////////////////////
	void Action2D::setProgress( F32 progress )
	{

	}
