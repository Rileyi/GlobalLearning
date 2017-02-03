<?php

namespace AppBundle\Controller;

use AppBundle\Entity\Word;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Cache;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Method;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\ParamConverter;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Security;

use Symfony\Component\EventDispatcher\GenericEvent;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

/**
 * Controller used to manage Words collection in the public part of the site.
 *
 * @Route("/words")
 *
 * @author Paul-Axel MARIE
 */
class WordController extends Controller
{
    /**
     * @Route("/", defaults={"_format"="html"}, name="central_index")
     * @Method("GET")
     * @Cache(smaxage="10")
     * @param $_format
     * @return Response
     */
    public function indexAction($_format)
    {
        //$entities = $this->getDoctrine()->getRepository(Post::class)->findLatest($page);
        $entities = false;
        return $this->render('central/index.'.$_format.'.twig', ['$entities' => $entities]);
    }

    /**
     * @Route("/login", defaults={"_format"="html"}, name="search_word")
     * @param $_format
     * @return Response
     */
    public function loginAction($_format)
    {
        //$helper = $this->get('security.authentication_utils');

        return $this->render('central/index.'.$_format.'.twig', [
            // last username entered by the user (if any)
            //'last_username' => $helper->getLastUsername(),
            // last authentication error (if any)
            //'error' => $helper->getLastAuthenticationError(),
        ]);
    }

    /**
     * @Route("/{word}")
     * @Method("GET")
     * @param $word
     * @return Response
     */
    public function getAction($word)
    {

        //$helper = $this->get('security.authentication_utils');

        return $this->render('central/word.html.twig', [
            // last username entered by the user (if any)
            'word' => $word,
            // last authentication error (if any)
            //'error' => $helper->getLastAuthenticationError(),
        ]);
    }
}