print( "test.lua" )
CallMeFromLua( )
CallMeFromLuaToo( 1, 2 )

function CallMeFromC( )
  print( "CallMeFromC" )
end

function CoroutineTest( self )
  while(true) do
    WaitSeconds( 1 )
    print( "CoroutineTest" )
    print( self )
  end
end
