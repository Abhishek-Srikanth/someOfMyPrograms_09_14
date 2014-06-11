package com.example.dodgeit;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Align;
import android.graphics.Paint.Style;
import android.graphics.RectF;
import android.graphics.Typeface;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;

import com.bsac.dodgeit.R;

public class gameView extends View
{
	private float prevTouchX;
	private float prevTouchY;
	private int xMax;
	private int yMax;
	private int remainder;
	private int obstacle_oscillator = 1;
	private RectF imgBounds;
	private Paint paint;
	
	private Bitmap bmp;
	
	private Context contxt;
	
	private Ball ball;
	private int num_obstacles = 1;
	private int obstacle_limit = 14;		// Change after testing
	/** This is a unique problem as in portrait mode it is possible
	 *  To complete an obstacle wave of magnitude 14.
	 *  On the other hand, it is nearly impossible to do the same in landscape
	 *  with even a wave of magnitude 10 seeming rather difficult...
	 *  
	 *  A well thought out procedure to set difficulties must be implemented
	 *  
	 *  yMax = 2*obstacle[i].getRadius()*num_obstacles + 4*ball.getRadius()
	 *
         *  yMax - 4*ball.getRadius() = num_obstacles
         *  -------------------------
         *  2*obstacle[i].getRadius()
	 */
	
	private Obstacle[] obstacle = new Obstacle[obstacle_limit];
//	private Bullet bullet;
	
	// CONSTRUCTOR
	public gameView(Context context)
	{
		super(context);
		contxt = context;	// so that obstacle construction can get context
							// it needs context so that sprite may be set

// 	1st BACKGROUND is plain, set in GameActivity
//		background();
		
		// CONSTRUCT OBJECTS BELOW
		ball = new Ball(xMax, yMax, context);	// to give image to ball
//		bullet = new Bullet(xMax, yMax);
		for(int i = 0; i < num_obstacles; ++i)
		{
			obstacle[i] = new Obstacle(xMax, yMax, i, num_obstacles, obstacle_oscillator, context);
			obstacle_oscillator *= -1;
		}
		imgBounds = new RectF();
		paint = new Paint();
		bmp = BitmapFactory.decodeResource(contxt.getResources(), R.drawable.evil_grin_sub);
		// FOR  TOUCH INPUT and hardware input as well!
		this.setFocusable(true);
		this.requestFocus();				// Asks focus for this View
		this.setFocusableInTouchMode(true);	// Allows touch controls
	}

	@Override
	protected void onDraw(Canvas canvas)
	{
		if(validityCheck())	// validityCheck is a boolean function that returns true if the ball is 
							// still alive, else it returns false
		{

///////////////////////////////////// DRAW BELOW //////////////////////////////////////////////////////

			ball.draw(canvas);
			for(int i = 0; i < num_obstacles; ++i)
			{
				if(obstacle[i].getCenterX() + obstacle[i].getRadius() > 0)
				{	
					obstacle[i].draw(canvas);
				}
			}
			
///////////////////////////////////// UPDATE BELOW ////////////////////////////////////////////////////

			ball.update();
			remainder = num_obstacles; 
			for(int i = 0; i < num_obstacles; ++i)
			{
			    if(obstacle[i].getCenterX() + obstacle[i].getRadius() > 0)
			    {
				obstacle[i].update();
				remainder--;
			    }
			}

			// LEVEL UP SCENARIO
			if(remainder==num_obstacles && num_obstacles != obstacle_limit)
			{
				for(int i = 0; i < num_obstacles; ++i)
				{
					obstacle[i].resetxMaxyMax(xMax,yMax, i, num_obstacles+1, obstacle_oscillator);
					obstacle_oscillator *= -1;
				}
				
				obstacle[num_obstacles] = new Obstacle(xMax, yMax, num_obstacles, num_obstacles+1, obstacle_oscillator, contxt);
				obstacle_oscillator *= -1;

/*increase level*/ num_obstacles++;	// increase level of difficulty	
				
				background();	// calls background setting function
				
			}
			// WIN SCENARIO
			else if(remainder==num_obstacles && num_obstacles == obstacle_limit)
			{
		// try to optimize this by checking if background matches or not
			    if(xMax > yMax)
				this.setBackgroundResource(R.drawable.win_la);
			    else
				this.setBackgroundResource(R.drawable.win);

			}
		}
		else	// LOSE SCENARIO
		{
		    canvas.drawColor(Color.RED);
		    String text1 = "YOU LOST!";
		    String text2 = "Score: " + num_obstacles;
//		    Paint paint = new Paint();
		    paint.setStyle(Style.FILL);
		    paint.setTypeface(Typeface.MONOSPACE);
		    paint.setColor(Color.GREEN);
		    paint.setTextAlign(Align.CENTER);	// aligns center!
		    paint.setTextSize(100);
//////////////  VALUES NEED TO BE CHANGED TO ACCOMMODATE BOTH AXES
		    canvas.drawText(text1, xMax/2, 2*yMax/6/*(xMax>yMax?3:4)*/, paint);
		    canvas.drawText(text2, xMax/2, 3*yMax/6/*(xMax>yMax?3:4)*/, paint);

//		    RectF imgBounds = new RectF();
//		    imgBounds.set(left, top, right, bottom);
		    imgBounds.set(0, yMax - yMax/6, xMax, yMax);
//		    canvas.drawBitmap(BitmapFactory.decodeResource(contxt.getResources(), R.drawable.evil_grin_sub), null, imgBounds, null);
		    canvas.drawBitmap(bmp, null, imgBounds, null);
		}
		try{Thread.sleep(30);} catch(InterruptedException e){}
		invalidate();
	}

	private boolean validityCheck() // validityCheck is a boolean function that returns true if the ball is 
									// still alive, else it returns false
	{
		for(int i = 0; i < num_obstacles; ++i)
		{
		    if( (ball.getCenterX() - obstacle[i].getCenterX())*(ball.getCenterX() - obstacle[i].getCenterX())
		       +(ball.getCenterY() - obstacle[i].getCenterY())*(ball.getCenterY() - obstacle[i].getCenterY())	
		       <(ball.getRadius() + obstacle[i].getRadius())*(ball.getRadius() + obstacle[i].getRadius()))
		    {
			return false;
		    }
		}
		return true;
	}

	@Override
	public boolean onTouchEvent(MotionEvent event)
	{
		if(validityCheck())
		{
			float currentTouchX = event.getX();
			float dX = currentTouchX - prevTouchX;
			if(event.getAction() == MotionEvent.ACTION_MOVE)
			{
				float scl = 1;
				if(xMax != 0 && yMax != 0)
				{
	//				scl = 50.0f / ( (xMax > yMax)? yMax : xMax );	// GET the scale size correct
					scl = (xMax / 100);
					if(yMax > xMax)
					{
						scl *= yMax/xMax;	// scales 
					}
				}
				else
				{
					scl = 20.0f;
				}
				ball.shiftBallOnXAxis( (dX>0?1:dX==0?0:-1) * scl );
			}		
			prevTouchX = currentTouchX;
			prevTouchY = event.getY();	// so that prevTouchY stays updated
		}
		else
		{
			if(event.getAction() == MotionEvent.ACTION_MOVE)
			{	
				float currentTouchY = event.getY();
				if(Math.abs(prevTouchY - currentTouchY) > yMax/4)	// swipe up or down
				// try 100 instead
				{
					num_obstacles = 1;
					onSizeChanged(xMax+1, yMax+1,0,0);
					background();
				}
				prevTouchY = currentTouchY;
			}
		}
		return true;
	}
	
	@Override
	public void onSizeChanged(int w, int h, int wOld, int hOld)
	{
		xMax = w - 1;
		yMax = h - 1;
		ball.resetxMaxyMax(xMax,yMax);
		for(int i = 0; i < num_obstacles; ++i)
		{
			obstacle[i].resetxMaxyMax(xMax,yMax, i, num_obstacles, obstacle_oscillator);
			obstacle_oscillator *= -1;
		}
	}	
	
	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event)
	{
		switch(keyCode)
		{
		case KeyEvent.KEYCODE_DPAD_RIGHT:
			ball.shiftBallOnXAxis( 20 );
			break;
		case KeyEvent.KEYCODE_DPAD_LEFT:
			ball.shiftBallOnXAxis( -20 );
			break;
		case KeyEvent.KEYCODE_DPAD_UP:
		case KeyEvent.KEYCODE_DPAD_DOWN:
			if(!validityCheck())
			{
				num_obstacles = 1;
				onSizeChanged(xMax+1, yMax+1,0,0);
				background();
			}
			break;
		}
		return true;
		
	}
	
	private void background()
	{
		int i = (int)(Math.random()*100)%16;	// i ranges from 0 to 15 => 16 values
		switch(i)
		{
			case 0:
				this.setBackgroundResource(R.drawable.brazil);
				break;
			case 1:
				this.setBackgroundResource(R.drawable.germany);
				break;
			case 2:
				this.setBackgroundResource(R.drawable.netherlands);
				break;
			case 3:
				this.setBackgroundResource(R.drawable.plain);
				break;
			case 4:
				this.setBackgroundResource(R.drawable.italy);
				break;
			case 5:
				this.setBackgroundResource(R.drawable.colombia);
				break;
			case 6:
				this.setBackgroundResource(R.drawable.uruguay);
				break;
			case 7:
				this.setBackgroundResource(R.drawable.england);
				break;
			case 8:
				this.setBackgroundResource(R.drawable.spain);
				break;
			case 9:
				this.setBackgroundResource(R.drawable.mexico);
				break;
			case 10:
				this.setBackgroundResource(R.drawable.argentina);
				break;
			case 11:
				this.setBackgroundResource(R.drawable.greece);
				break;
			case 12:
				this.setBackgroundResource(R.drawable.portugal);
				break;
			case 13:
				this.setBackgroundResource(R.drawable.france);
				break;
			case 14:
				this.setBackgroundResource(R.drawable.singapore);
				break;
			case 15:
				this.setBackgroundResource(R.drawable.basic);
				break;
//			case 16:
//				this.setBackgroundResource(R.drawable.stonehenge);
//				break;
		}
	}
}
