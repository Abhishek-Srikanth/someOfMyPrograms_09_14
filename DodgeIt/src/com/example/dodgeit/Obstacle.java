package com.example.dodgeit;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.RectF;
import com.bsac.dodgeit.R;

public class Obstacle 
{
	private int centerX;
	private int centerY;
	private int radius;
	private int speedYAxis;
	
	private Context context;
	private int villainAngle = 0;
	
	private RectF obsBounds;
	private int xMax;
	private int yMax;
	public void resetxMaxyMax(int x, int y, int obsNumber, int numberObstacles, int movement)
	{
		if(numberObstacles == 0)
		{
			numberObstacles = 1;
		}
		xMax = x;
		yMax = y;
		speedYAxis = 15 + ((int)(Math.random()>0.5?1:-1))
							*((int)( Math.random()*10) /* whole equation results in 15 +/- 0-10 */ ) ;
		// increase speed if it is in portrait mode
		speedYAxis += (yMax > xMax ? 5/*Portrait*/ : 0/*Landscape*/ ); 
		speedYAxis *= movement;
				
		centerX = xMax - (10 + radius);
		centerY = ( (int)((Math.random() + obsNumber) * yMax/numberObstacles ) + radius);

		if(centerY - radius < 0){centerY += radius;}	// So that it does not fly out at the top
		else if(centerY < 0){centerY += 2*radius;}
		if(centerY + radius > yMax){centerY -= radius;}	// So that it does not fly out at the bottom
		else if(centerY > yMax){centerY -= 2*radius;}

	}
	
	public Obstacle(int XMAX, int YMAX, int obsNumber, int numberObstacles, int movement, Context c)
	{
		context = c;
		
		if(numberObstacles == 0)
		{numberObstacles++;}
		xMax = XMAX;
		yMax = YMAX;
		
		speedYAxis = 15 + ((int)(Math.random()>0.5?1:-1))
				*((int)( Math.random()*10) /* whole equation results in 15 +/- 0-10 */ ) ;
		// increase speed if it is in portrait mode
		speedYAxis += (yMax > xMax ? 5/*Portrait*/ : 0/*Landscape*/ ); 
		speedYAxis *= movement;

		radius = 30;
		centerX = xMax - (10 + radius);
		centerY = ( (int)((Math.random() + obsNumber) * yMax/numberObstacles ) + radius);
		
		if(centerY - radius < 0){centerY += radius;}	// So that it does not fly out at the top
		else if(centerY < 0){centerY += 2*radius;}
		if(centerY + radius > yMax){centerY -= radius;}	// So that it does not fly out at the bottom
		else if(centerY > yMax){centerY -= 2*radius;}

		obsBounds = new RectF();
	}
	
	public void draw(Canvas canvas)
	{
		obsBounds.set(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
		
// following code is to make the obstacle rotate for a little while
		if(villainAngle == 270 || villainAngle == 270 + 45)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.villain), null, obsBounds, null);
		}
		else if(villainAngle == 0 || villainAngle == 0 + 45)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.villain270), null, obsBounds, null);
		}
		else if(villainAngle == 90 || villainAngle == 90 + 45)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.villain180), null, obsBounds, null);
		}
		else if(villainAngle == 180 || villainAngle == 180 + 45)
		{
			canvas.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.villain90), null, obsBounds, null);
		}
		villainAngle += 45;
		if(villainAngle==360){villainAngle=0;}
	}
	
	public void update()
	{
		centerX -= (xMax > yMax) ? (13 + (int)(Math.random()>0.5?1:-1)*(int)(Math.random()*10)) 
								 : (10 + (int)(Math.random()>0.5?1:-1)*(int)(Math.random()* 8));
		
		centerY += speedYAxis;
		// v TRY NOT TO CHANGE AS IT STARTS ACTING FUNNY
		if(centerY + radius > yMax || centerY - radius < 0)
		{
			centerY = centerY - speedYAxis;
			speedYAxis  = speedYAxis * (-1);
		}
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
