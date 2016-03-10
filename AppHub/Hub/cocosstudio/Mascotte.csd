<GameFile>
  <PropertyGroup Name="Mascotte" Type="Node" ID="557ef2bd-3315-4c25-91ea-a80cf00ce789" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="24" Speed="1.0000" ActivedAnimationName="Aie">
        <Timeline ActionTag="960319600" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="24" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-2138097952" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="24" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1050501197" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="2" X="2.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="4" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="6" X="0.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="8" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="2.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="12" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="14" X="0.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="16" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="18" X="2.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="22" X="0.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="24" X="0.0000" Y="12.0692">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Aie" StartIndex="0" EndIndex="24">
          <RenderColor A="150" R="0" G="139" B="139" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="29" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Bulle_vide" ActionTag="293181045" Tag="31" IconVisible="False" LeftMargin="-223.0970" RightMargin="-230.9030" TopMargin="-417.4990" BottomMargin="105.4990" ctype="SpriteObjectData">
            <Size X="454.0000" Y="312.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="3.9030" Y="261.4990" />
            <Scale ScaleX="0.9264" ScaleY="0.9264" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="bulle_vide.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text" ActionTag="960319600" VisibleForFrame="False" Tag="32" IconVisible="False" LeftMargin="-159.5000" RightMargin="-167.5000" TopMargin="-349.1260" BottomMargin="244.1260" FontSize="30" LabelText="Bonjour,&#xA;je remplace Shahoots en&#xA;attendant qu'il arrive." TouchScaleChangeAble="True" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="327.0000" Y="105.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="4.0000" Y="296.6260" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_aie" ActionTag="-2138097952" Tag="33" IconVisible="False" LeftMargin="-140.5000" RightMargin="-148.5000" TopMargin="-314.1253" BottomMargin="279.1253" FontSize="30" LabelText="Mais euh ça fait mal :(" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="289.0000" Y="35.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="4.0000" Y="296.6253" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button" ActionTag="1050501197" Tag="40" IconVisible="False" LeftMargin="-34.5000" RightMargin="-34.5000" TopMargin="-56.0692" BottomMargin="-31.9308" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="39" Scale9Height="66" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="69.0000" Y="88.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="12.0692" />
            <Scale ScaleX="2.2821" ScaleY="2.2714" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="shahoots_remplacant.png" Plist="" />
            <NormalFileData Type="Normal" Path="shahoots_remplacant.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>