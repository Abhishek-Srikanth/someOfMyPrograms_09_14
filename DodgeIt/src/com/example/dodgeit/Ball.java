package com.example.dodgeit;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import com.bsac.dodgeit.R;

public class Ball 
{
	private int centerX;
	private int centerY;
	private int radius;
	private int speedYAxis;
	private RectF ballBounds;
	private Paint ballPaint;
	private int xMax;
	private int yMax;
	
	private int ball_state = 0;	  // degrees (0 -> 90 -> 180 -> 270 -> 0) starts vertical
																		// first clip will be 90 deg
	
	private Context context;
	
	public Ball(int XMAX, int YMAX, Context c)
	{		
		context = c;
		
		xMax = XMAX;
		yMax = YMAX;
		
		speedYAxis = 25;
		radius = 60;
		centerX = 20 + radius;
		centerY = 40 + radius;
		ballBounds = new RectF();
		ballPaint = new Paint();
	}
	
	public void draw(Canvas canvas)
	{
		ballBounds.set(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
		ballPaint.setColor(Color.CYAN);
// following if else-if ladder is to make the ball rotate
		if(ball_state == 270 || ball_state == 315)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.ball), null, ballBounds, null);
		}
		else if(ball_state == 0 || ball_state == 45)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.ball90), null, ballBounds, null);
		}
		else if(ball_state == 90 || ball_state == 135)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.ball180), null, ballBounds, null);
		}
		else if(ball_state == 180 || ball_state == 225)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.ball270), null, ballBounds, null);
		}
		ball_state += 45;
		if(ball_state == 360){ball_state = 0;}
		
//		canvas.drawOval(ballBounds, ballPaint);
	}
	
	public void update()
	{
		centerY += speedYAxis;
		if(centerY + radius > yMax)
		{
			centerY -= speedYAxis;
			speedYAxis *= -1;
		}
		else if(centerY - radius < 0)
		{
			centerY -= speedYAxis;
			speedYAxis *= -1;
		}
	}

	public void shiftBallOnXAxis(float shiftX)
	{
		// can shorten this code...  well obviously, by making it condition only!
		centerX += shiftX;
		if(centerX - radius < 0 || centerX + radius > xMax)
		{
			centerX -= shiftX;
		}
	}
	
	public void resetxMaxyMax(int x, int y)
	{
		xMax = x;
		yMax = y;
		centerX = 20 + radius;
		centerY = 40 + radius;
	}
	
	public int getCenterX() 
	{
		return centerX;
	}

	public int getCenterY() 
	{
		return centerY;
	}

	public int getRadius() 
	{
		return radius;
	}

}
