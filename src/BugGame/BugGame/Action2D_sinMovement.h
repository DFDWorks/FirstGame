////////////////////////////////////////
// Action2D_sinMovement.h
//
// Authors: Fomin Eugene
//
// Description:
////////////////////////////////////////


////////////////////////////////////
#ifndef _Action2D_sinMovement_h_
#define _Action2D_sinMovement_h_


////////////////////////////////////
// Include
#include "TimeAction2D.h"

	////////////////////////////////////
	// Typedef
	PTR( Action2D_sinMovement );


	////////////////////////////////////
	// Class Action2D_sinMovement
	class Action2D_sinMovement
		: public TimeAction2D
	{
	public:


	public:
		
		////////////////////////////////////
		virtual ~Action2D_sinMovement();

		////////////////////////////////////
		static Action2D_sinMovementPtr Create( F32 time = 4.0f, F32 amplitude = 10.0f );

		////////////////////////////////////
		static Action2D_sinMovementPtr Create( const Action2D_sinMovementPtr& obj );

		////////////////////////////////////
		virtual bool play() OVERRIDE;

		////////////////////////////////////
		F32 getAmplitude() const { return m_amplitude; }

		////////////////////////////////////
		void setAmplitude( F32 amplitude ){ m_amplitude = amplitude; }

		////////////////////////////////////
		bool getIsXAxis() const { return m_isXAxis; }

		////////////////////////////////////
		void setIsXAxis( bool isXAxis ){ m_isXAxis = isXAxis; }

	protected:
		
		////////////////////////////////////
		Action2D_sinMovement();

		////////////////////////////////////
		bool init( F32 time = 4.0f, F32 amplitude = 10.0f );

		////////////////////////////////////
		bool init( const Action2D_sinMovementPtr& obj );
        

		////////////////////////////////////
		virtual void setProgress( F32 progress ) OVERRIDE;

	protected:
		F32 m_amplitude;
		bool m_isXAxis;

	private:
		F32 m_lastProgress;
	};
    
#endif // _Action2D_sinMovement_h_
////////////////////////////////////
