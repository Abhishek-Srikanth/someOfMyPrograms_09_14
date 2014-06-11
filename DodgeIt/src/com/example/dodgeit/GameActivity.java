package com.example.dodgeit;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import com.bsac.dodgeit.R;

public class GameActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		View gameView = new gameView(this);
		setContentView(gameView);
		gameView.setBackgroundResource(R.drawable.plain);
	}
}
