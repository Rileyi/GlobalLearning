<GameFile>
  <PropertyGroup Name="ToolBar" Type="Node" ID="3dd28744-61e8-4df5-baa4-c56865c1c92a" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="21" Speed="1.0000" ActivedAnimationName="menu_to_other">
        <Timeline ActionTag="224273702" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="21" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1636398899" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="21" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-1064289552" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="21" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1504601253" Property="Position">
          <PointFrame FrameIndex="0" X="-439.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="1" X="0.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="0.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="21" X="-439.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="other_to_menu" StartIndex="0" EndIndex="1">
          <RenderColor A="150" R="50" G="205" B="50" />
        </AnimationInfo>
        <AnimationInfo Name="menu_to_other" StartIndex="20" EndIndex="21">
          <RenderColor A="150" R="0" G="0" B="255" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="ToolBar" Tag="57" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Background_toolbar" ActionTag="-1647065923" Tag="62" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-512.0000" RightMargin="-518.0000" BottomMargin="-86.0000" ctype="SpriteObjectData">
            <Size X="1030.0000" Y="86.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="-512.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="barres/Header placeholder.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Shahoots_button" ActionTag="224273702" VisibleForFrame="False" Tag="58" IconVisible="False" LeftMargin="304.0000" RightMargin="-365.0000" TopMargin="5.0000" BottomMargin="-62.0000" TouchEnable="True" FontSize="20" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="31" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="61.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text" ActionTag="652807721" Tag="66" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="67.1000" RightMargin="-131.1000" TopMargin="7.0000" BottomMargin="7.0000" FontSize="30" LabelText="Shahoots" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="125.0000" Y="43.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="67.1000" Y="28.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.1000" Y="0.5000" />
                <PreSize X="2.0492" Y="0.7544" />
                <FontResource Type="Normal" Path="Fonts/ChalkboardSE.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="1.0000" />
            <Position X="304.0000" Y="-5.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Header Shahoots ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Header Shahoots ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Header Shahoots.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Valid_button" ActionTag="1636398899" VisibleForFrame="False" Tag="59" IconVisible="False" LeftMargin="27.0000" RightMargin="-90.0000" TopMargin="5.0000" BottomMargin="-62.0000" TouchEnable="True" FontSize="20" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="33" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="63.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text" ActionTag="336049892" Tag="65" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="69.3000" RightMargin="-71.3000" TopMargin="7.0000" BottomMargin="7.0000" FontSize="30" LabelText="Valid" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="65.0000" Y="43.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="69.3000" Y="28.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.1000" Y="0.5000" />
                <PreSize X="1.0317" Y="0.7544" />
                <FontResource Type="Normal" Path="Fonts/ChalkboardSE.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="1.0000" />
            <Position X="27.0000" Y="-5.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Header Validate ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Header Validate ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Header Validate.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Restart_button" ActionTag="-1064289552" VisibleForFrame="False" Tag="60" IconVisible="False" LeftMargin="-250.0000" RightMargin="187.0000" TopMargin="5.0000" BottomMargin="-62.0000" TouchEnable="True" FontSize="20" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="33" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="63.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text" ActionTag="-2004499571" Tag="64" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="69.3000" RightMargin="-112.3000" TopMargin="7.0000" BottomMargin="7.0000" FontSize="30" LabelText="Restart" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="106.0000" Y="43.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="69.3000" Y="28.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.1000" Y="0.5000" />
                <PreSize X="1.6825" Y="0.7544" />
                <FontResource Type="Normal" Path="Fonts/ChalkboardSE.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="1.0000" />
            <Position X="-250.0000" Y="-5.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Header Restart ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Header Restart ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Header Restart.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Menu_button" ActionTag="1504601253" Tag="61" IconVisible="False" LeftMargin="-502.0000" RightMargin="439.0000" TopMargin="5.0000" BottomMargin="-62.0000" TouchEnable="True" FontSize="20" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="33" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="63.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text" ActionTag="-550619860" Tag="63" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="69.3000" RightMargin="-82.3000" TopMargin="7.0000" BottomMargin="7.0000" FontSize="30" LabelText="Menu" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="76.0000" Y="43.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="69.3000" Y="28.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.1000" Y="0.5000" />
                <PreSize X="1.2063" Y="0.7544" />
                <FontResource Type="Normal" Path="Fonts/ChalkboardSE.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="1.0000" ScaleY="1.0000" />
            <Position X="-439.0000" Y="-5.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Header Menu ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Header Menu ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Header Menu.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>